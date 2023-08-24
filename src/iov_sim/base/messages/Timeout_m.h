//
// Generated file, do not edit! Created by opp_msgtool 6.0 from iov_sim/base/messages/Timeout.msg.
//

#ifndef __IOV_SIM_TIMEOUT_M_H
#define __IOV_SIM_TIMEOUT_M_H

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

class Timeout;

}  // namespace iov_sim

#include "iov_sim/base/messages/BaseMessage_m.h" // import iov_sim.base.messages.BaseMessage


namespace iov_sim {

/**
 * Class generated from <tt>iov_sim/base/messages/Timeout.msg:27</tt> by opp_msgtool.
 * <pre>
 * packet Timeout extends BaseMessage
 * {
 *     double timeout;
 * }
 * </pre>
 */
class IOV_SIM_API Timeout : public ::iov_sim::BaseMessage
{
  protected:
    double timeout = 0;

  private:
    void copy(const Timeout& other);

  protected:
    bool operator==(const Timeout&) = delete;

  public:
    Timeout(const char *name=nullptr, short kind=0);
    Timeout(const Timeout& other);
    virtual ~Timeout();
    Timeout& operator=(const Timeout& other);
    virtual Timeout *dup() const override {return new Timeout(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual double getTimeout() const;
    virtual void setTimeout(double timeout);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Timeout& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Timeout& obj) {obj.parsimUnpack(b);}


}  // namespace iov_sim


namespace omnetpp {

template<> inline iov_sim::Timeout *fromAnyPtr(any_ptr ptr) { return check_and_cast<iov_sim::Timeout*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __IOV_SIM_TIMEOUT_M_H
