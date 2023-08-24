//
// Generated file, do not edit! Created by opp_msgtool 6.0 from iov_sim/modules/messages/model/RSUCheckModelInit.msg.
//

#ifndef __IOV_SIM_RSUCHECKMODELINIT_M_H
#define __IOV_SIM_RSUCHECKMODELINIT_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

// dll export symbol
#ifndef IOV_SIM_API
#  if defined(IOV_SIM_EXPORT)
#    define IOV_SIM_API  OPP_DLLEXPORT
#  elif defined(IOV_SIM_IMPORT)
#    define IOV_SIM_API  OPP_DLLIMPORT
#  else
#    define IOV_SIM_API
#  endif
#endif


namespace iov_sim {

class RSUCheckModelInit;

}  // namespace iov_sim

#include "iov_sim/modules/messages/model/ModelBaseMessage_m.h" // import iov_sim.modules.messages.model.ModelBaseMessage


namespace iov_sim {

/**
 * Class generated from <tt>iov_sim/modules/messages/model/RSUCheckModelInit.msg:27</tt> by opp_msgtool.
 * <pre>
 * packet RSUCheckModelInit extends ModelBaseMessage
 * {
 *     string requestingNode;
 *     double signalStrength;
 * }
 * </pre>
 */
class IOV_SIM_API RSUCheckModelInit : public ::iov_sim::ModelBaseMessage
{
  protected:
    ::omnetpp::opp_string requestingNode;
    double signalStrength = 0;

  private:
    void copy(const RSUCheckModelInit& other);

  protected:
    bool operator==(const RSUCheckModelInit&) = delete;

  public:
    RSUCheckModelInit(const char *name=nullptr, short kind=0);
    RSUCheckModelInit(const RSUCheckModelInit& other);
    virtual ~RSUCheckModelInit();
    RSUCheckModelInit& operator=(const RSUCheckModelInit& other);
    virtual RSUCheckModelInit *dup() const override {return new RSUCheckModelInit(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual const char * getRequestingNode() const;
    virtual void setRequestingNode(const char * requestingNode);

    virtual double getSignalStrength() const;
    virtual void setSignalStrength(double signalStrength);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const RSUCheckModelInit& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, RSUCheckModelInit& obj) {obj.parsimUnpack(b);}


}  // namespace iov_sim


namespace omnetpp {

template<> inline iov_sim::RSUCheckModelInit *fromAnyPtr(any_ptr ptr) { return check_and_cast<iov_sim::RSUCheckModelInit*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __IOV_SIM_RSUCHECKMODELINIT_M_H
