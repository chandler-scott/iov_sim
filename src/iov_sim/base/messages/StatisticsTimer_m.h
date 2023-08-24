//
// Generated file, do not edit! Created by opp_msgtool 6.0 from iov_sim/base/messages/StatisticsTimer.msg.
//

#ifndef __IOV_SIM_STATISTICSTIMER_M_H
#define __IOV_SIM_STATISTICSTIMER_M_H

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

class StatisticsTimer;

}  // namespace iov_sim

#include "iov_sim/base/messages/Timer_m.h" // import iov_sim.base.messages.Timer


namespace iov_sim {

/**
 * Class generated from <tt>iov_sim/base/messages/StatisticsTimer.msg:27</tt> by opp_msgtool.
 * <pre>
 * packet StatisticsTimer extends Timer
 * {
 * }
 * </pre>
 */
class IOV_SIM_API StatisticsTimer : public ::iov_sim::Timer
{
  protected:

  private:
    void copy(const StatisticsTimer& other);

  protected:
    bool operator==(const StatisticsTimer&) = delete;

  public:
    StatisticsTimer(const char *name=nullptr, short kind=0);
    StatisticsTimer(const StatisticsTimer& other);
    virtual ~StatisticsTimer();
    StatisticsTimer& operator=(const StatisticsTimer& other);
    virtual StatisticsTimer *dup() const override {return new StatisticsTimer(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const StatisticsTimer& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, StatisticsTimer& obj) {obj.parsimUnpack(b);}


}  // namespace iov_sim


namespace omnetpp {

template<> inline iov_sim::StatisticsTimer *fromAnyPtr(any_ptr ptr) { return check_and_cast<iov_sim::StatisticsTimer*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __IOV_SIM_STATISTICSTIMER_M_H

