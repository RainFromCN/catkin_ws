// Generated by gencpp from file astra_camera/GetIRGainResponse.msg
// DO NOT EDIT!


#ifndef ASTRA_CAMERA_MESSAGE_GETIRGAINRESPONSE_H
#define ASTRA_CAMERA_MESSAGE_GETIRGAINRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace astra_camera
{
template <class ContainerAllocator>
struct GetIRGainResponse_
{
  typedef GetIRGainResponse_<ContainerAllocator> Type;

  GetIRGainResponse_()
    : gain(0)  {
    }
  GetIRGainResponse_(const ContainerAllocator& _alloc)
    : gain(0)  {
  (void)_alloc;
    }



   typedef int32_t _gain_type;
  _gain_type gain;





  typedef boost::shared_ptr< ::astra_camera::GetIRGainResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::astra_camera::GetIRGainResponse_<ContainerAllocator> const> ConstPtr;

}; // struct GetIRGainResponse_

typedef ::astra_camera::GetIRGainResponse_<std::allocator<void> > GetIRGainResponse;

typedef boost::shared_ptr< ::astra_camera::GetIRGainResponse > GetIRGainResponsePtr;
typedef boost::shared_ptr< ::astra_camera::GetIRGainResponse const> GetIRGainResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::astra_camera::GetIRGainResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::astra_camera::GetIRGainResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::astra_camera::GetIRGainResponse_<ContainerAllocator1> & lhs, const ::astra_camera::GetIRGainResponse_<ContainerAllocator2> & rhs)
{
  return lhs.gain == rhs.gain;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::astra_camera::GetIRGainResponse_<ContainerAllocator1> & lhs, const ::astra_camera::GetIRGainResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace astra_camera

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::astra_camera::GetIRGainResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::astra_camera::GetIRGainResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::astra_camera::GetIRGainResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::astra_camera::GetIRGainResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::astra_camera::GetIRGainResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::astra_camera::GetIRGainResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::astra_camera::GetIRGainResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "164d2201bda8580473ff7023ba27f703";
  }

  static const char* value(const ::astra_camera::GetIRGainResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x164d2201bda85804ULL;
  static const uint64_t static_value2 = 0x73ff7023ba27f703ULL;
};

template<class ContainerAllocator>
struct DataType< ::astra_camera::GetIRGainResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "astra_camera/GetIRGainResponse";
  }

  static const char* value(const ::astra_camera::GetIRGainResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::astra_camera::GetIRGainResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 gain\n"
;
  }

  static const char* value(const ::astra_camera::GetIRGainResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::astra_camera::GetIRGainResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.gain);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetIRGainResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::astra_camera::GetIRGainResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::astra_camera::GetIRGainResponse_<ContainerAllocator>& v)
  {
    s << indent << "gain: ";
    Printer<int32_t>::stream(s, indent + "  ", v.gain);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ASTRA_CAMERA_MESSAGE_GETIRGAINRESPONSE_H
