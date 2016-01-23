/***************************************************************
 * Generated by Hottentot CC Generator
 * Date: 23-01-2016 11:53:02
 * Name: status.h
 * Description:
 *   This file contains definition of Status class.
 ***************************************************************/

#ifndef _IR_NTNAEEM_GATE__STATUS_H_
#define _IR_NTNAEEM_GATE__STATUS_H_

#include <string>

#include <naeem/hottentot/runtime/types/primitives.h>
#include <naeem/hottentot/runtime/serializable.h>


namespace ir {
namespace ntnaeem {
namespace gate {
  class Status : public ::naeem::hottentot::runtime::Serializable {
  public:
    Status() {}
    ~Status() {}
  public:
    inline ::naeem::hottentot::runtime::types::UInt32 GetStatusCode() const {
      return statusCode_;
    }
    inline void SetStatusCode(::naeem::hottentot::runtime::types::UInt32 statusCode) {
      statusCode_ = statusCode;
    }
  public:
    virtual unsigned char * Serialize(uint32_t * /* Pointer to length */);
    virtual void Deserialize(unsigned char * /* Data */, uint32_t /* Data length */);
  private:
    ::naeem::hottentot::runtime::types::UInt32 statusCode_;
  };
} // END OF NAMESPACE gate
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir

#endif