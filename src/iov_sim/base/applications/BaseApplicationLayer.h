//
// Copyright (C) 2016 David Eckhoff <eckhoff@cs.fau.de>
//
// Documentation for these modules is at http://veins.car2x.org/
//
// SPDX-License-Identifier: GPL-2.0-or-later
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#pragma once

#include <map>
#include "iov_sim/iov_sim.h"


#include "veins/base/modules/BaseApplLayer.h"
#include "veins/modules/utility/Consts80211p.h"
#include "veins/modules/messages/BaseFrame1609_4_m.h"
#include "veins/modules/messages/DemoServiceAdvertisement_m.h"
#include "veins/modules/messages/DemoSafetyMessage_m.h"
#include "veins/base/connectionManager/ChannelAccess.h"
#include "veins/modules/mac/ieee80211p/DemoBaseApplLayerToMac1609_4Interface.h"
#include "veins/modules/mobility/traci/TraCIMobility.h"
#include "veins/modules/mobility/traci/TraCICommandInterface.h"
#include "veins/modules/phy/DeciderResult80211.h"
#include "veins/base/phyLayer/PhyToMacControlInfo.h"
#include "iov_sim/base/python/BaseWrapper.h"
#include "iov_sim/base/util/Logger.h"
#include "iov_sim/base/messages/Timeout_m.h"
#include "iov_sim/base/messages/Timer_m.h"
#include "iov_sim/modules/messages/model/ModelRequest_m.h"
#include "iov_sim/modules/messages/model/ModelUpdate_m.h"
#include "iov_sim/modules/messages/cluster/ClusterHeartbeat_m.h"
#include "iov_sim/modules/messages/cluster/ClusterHeartbeatReply_m.h"
#include "iov_sim/modules/messages/cluster/ClusterJoin_m.h"
#include "iov_sim/modules/messages/election/Ack_m.h"
#include "iov_sim/modules/messages/election/AckTimeout_m.h"
#include "iov_sim/modules/messages/election/Election_m.h"
#include "iov_sim/modules/messages/election/ElectionTimeout_m.h"
#include "iov_sim/modules/messages/election/Leader_m.h"
#include "iov_sim/modules/messages/election/Probe_m.h"
#include "iov_sim/modules/messages/election/Reply_m.h"
#include "iov_sim/modules/messages/neighbor/NeighborBeacon_m.h"
#include "iov_sim/base/util/Color.h"




using namespace veins;
namespace iov_sim {

using veins::AnnotationManager;
using veins::AnnotationManagerAccess;
using veins::TraCICommandInterface;
using veins::TraCIMobility;
using veins::TraCIMobilityAccess;

/**
 * @brief
 * Application layer base class.
 *
 * @author Chandler Scott
 *
 * @ingroup applLayer
 *
 * @see BaseApplLayer
 * @see Mac1609_4
 * @see PhyLayer80211p
 * @see Decider80211p
 */
class IOV_SIM_API BaseApplicationLayer : public BaseApplLayer {

public:
    ~BaseApplicationLayer() override;
    void initialize(int stage) override;
    void finish() override;

    void receiveSignal(cComponent* source, simsignal_t signalID, cObject* obj, cObject* details) override;

    enum DemoApplMessageKinds {
        SEND_BEACON_EVT,
        SEND_WSA_EVT
    };

protected:
    void setDisplayColor(const Color& color);

    double getSignalStrength(BaseMessage* msg);

    void sendModelUpdateMessage(const char* destination, const char* pNet, const char* vNet, const char* origin = "rsu");


    /** @brief handle messages from below and calls the onWSM, onBSM, and onWSA functions accordingly */
    void handleLowerMsg(cMessage* msg) override;

    /** @brief handle self messages */
    void handleSelfMsg(cMessage* msg) override;

    /** @brief sets all the necessary fields in the WSM, BSM, or WSA. */
    virtual void populateWSM(BaseFrame1609_4* wsm, LAddress::L2Type rcvId = LAddress::L2BROADCAST(), int serial = 0);

    /*@brief this function is called upon receiving a Model Message*/
    virtual void onModelMsg(BaseMessage* msg) {};

    /*@brief this function is called upon receiving an Election Message*/
    virtual void onElectionMsg(BaseMessage* msg) {};

    /*@brief this function is called upon receiving a Cluster Message*/
    virtual void onClusterMsg(BaseMessage* msg) {};

    /*@brief this function is called upon receiving a Neighbor Message*/
    virtual void onNeighborMsg(BaseMessage* msg) {};

    /** @brief this function is called every time the vehicle receives a position update signal */
    virtual void handlePositionUpdate(cObject* obj);

    /** @brief this function is called every time the vehicle parks or starts moving again */
    virtual void handleParkingUpdate(cObject* obj);

    /** @brief This will start the periodic advertising of the new service on the CCH
     *
     *  @param channel the channel on which the service is provided
     *  @param serviceId a service ID to be used with the service
     *  @param serviceDescription a literal description of the service
     */
    virtual void startService(Channel channel, int serviceId, std::string serviceDescription);

    /** @brief stopping the service and advertising for it */
    virtual void stopService();

    /** @brief compute a point in time that is guaranteed to be in the correct channel interval plus a random offset
     *
     * @param interval the interval length of the periodic message
     * @param chantype the type of channel, either type_CCH or type_SCH
     */
    virtual simtime_t computeAsynchronousSendingTime(simtime_t interval, ChannelType chantype);

    /**
     * @brief overloaded for error handling and stats recording purposes
     *
     * @param msg the message to be sent. Must be a WSM/BSM/WSA
     */
    virtual void sendDown(cMessage* msg);

    /**
     * @brief overloaded for error handling and stats recording purposes
     *
     * @param msg the message to be sent. Must be a WSM/BSM/WSA
     * @param delay the delay for the message
     */
    virtual void sendDelayedDown(cMessage* msg, simtime_t delay);

    /**
     * @brief helper function for error handling and stats recording purposes
     *
     * @param msg the message to be checked and tracked
     */
    virtual void checkAndTrackPacket(cMessage* msg);

protected:
    /* pointers ill be set when used with TraCIMobility */
    TraCIMobility* mobility;
    TraCICommandInterface* traci;
    TraCICommandInterface::Vehicle* traciVehicle;
    const char* nodeName;

    AnnotationManager* annotations;
    DemoBaseApplLayerToMac1609_4Interface* mac;


    /* support for parking currently only works with TraCI */
    bool isParked;

    /* BSM (beacon) settings */
    uint32_t beaconLengthBits;
    uint32_t beaconUserPriority;
    simtime_t beaconInterval;
    bool sendBeacons;

    /* WSM (data) settings */
    uint32_t dataLengthBits;
    uint32_t dataUserPriority;
    bool dataOnSch;

    /* WSA settings */
    int currentOfferedServiceId;
    std::string currentServiceDescription;
    Channel currentServiceChannel;
    simtime_t wsaInterval;

    /* state of the vehicle */
    Coord curPosition;
    Coord curSpeed;
    LAddress::L2Type myId = 0;
    int mySCH;

    /* stats */
    uint32_t generatedWSMs;
    uint32_t generatedWSAs;
    uint32_t generatedBSMs;
    uint32_t receivedWSMs;
    uint32_t receivedWSAs;
    uint32_t receivedBSMs;

    /* messages for periodic events such as beacon and WSA transmissions */
    cMessage* sendBeaconEvt;
    cMessage* sendWSAEvt;
};

} // namespace iov_sim
