// Generated by gencpp from file astra_camera/SetIRFlood.msg
// DO NOT EDIT!


#ifndef ASTRA_CAMERA_MESSAGE_SETIRFLOOD_H
#define ASTRA_CAMERA_MESSAGE_SETIRFLOOD_H

#include <ros/service_traits.h>


#include <astra_camera/SetIRFloodRequest.h>
#include <astra_camera/SetIRFloodResponse.h>


namespace astra_camera
{

struct SetIRFlood
{

typedef SetIRFloodRequest Request;
typedef SetIRFloodResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SetIRFlood
} // namespace astra_camera


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::astra_camera::SetIRFlood > {
  static const char* value()
  {
    return "8c1211af706069c994c06e00eb59ac9e";
  }

  static const char* value(const ::astra_camera::SetIRFlood&) { return value(); }
};

template<>
struct DataType< ::astra_camera::SetIRFlood > {
  static const char* value()
  {
    return "astra_camera/SetIRFlood";
  }

  static const char* value(const ::astra_camera::SetIRFlood&) { return value(); }
};


// service_traits::MD5Sum< ::astra_camera::SetIRFloodRequest> should match
// service_traits::MD5Sum< ::astra_camera::SetIRFlood >
template<>
struct MD5Sum< ::astra_camera::SetIRFloodRequest>
{
  static const char* value()
  {
    return MD5Sum< ::astra_camera::SetIRFlood >::value();
  }
  static const char* value(const ::astra_camera::SetIRFloodRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::astra_camera::SetIRFloodRequest> should match
// service_traits::DataType< ::astra_camera::SetIRFlood >
template<>
struct DataType< ::astra_camera::SetIRFloodRequest>
{
  static const char* value()
  {
    return DataType< ::astra_camera::SetIRFlood >::value();
  }
  static const char* value(const ::astra_camera::SetIRFloodRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::astra_camera::SetIRFloodResponse> should match
// service_traits::MD5Sum< ::astra_camera::SetIRFlood >
template<>
struct MD5Sum< ::astra_camera::SetIRFloodResponse>
{
  static const char* value()
  {
    return MD5Sum< ::astra_camera::SetIRFlood >::value();
  }
  static const char* value(const ::astra_camera::SetIRFloodResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::astra_camera::SetIRFloodResponse> should match
// service_traits::DataType< ::astra_camera::SetIRFlood >
template<>
struct DataType< ::astra_camera::SetIRFloodResponse>
{
  static const char* value()
  {
    return DataType< ::astra_camera::SetIRFlood >::value();
  }
  static const char* value(const ::astra_camera::SetIRFloodResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // ASTRA_CAMERA_MESSAGE_SETIRFLOOD_H
