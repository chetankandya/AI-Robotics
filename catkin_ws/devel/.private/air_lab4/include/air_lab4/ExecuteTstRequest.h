// Generated by gencpp from file air_lab4/ExecuteTstRequest.msg
// DO NOT EDIT!


#ifndef AIR_LAB4_MESSAGE_EXECUTETSTREQUEST_H
#define AIR_LAB4_MESSAGE_EXECUTETSTREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace air_lab4
{
template <class ContainerAllocator>
struct ExecuteTstRequest_
{
  typedef ExecuteTstRequest_<ContainerAllocator> Type;

  ExecuteTstRequest_()
    : tst_file()  {
    }
  ExecuteTstRequest_(const ContainerAllocator& _alloc)
    : tst_file(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _tst_file_type;
  _tst_file_type tst_file;





  typedef boost::shared_ptr< ::air_lab4::ExecuteTstRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::air_lab4::ExecuteTstRequest_<ContainerAllocator> const> ConstPtr;

}; // struct ExecuteTstRequest_

typedef ::air_lab4::ExecuteTstRequest_<std::allocator<void> > ExecuteTstRequest;

typedef boost::shared_ptr< ::air_lab4::ExecuteTstRequest > ExecuteTstRequestPtr;
typedef boost::shared_ptr< ::air_lab4::ExecuteTstRequest const> ExecuteTstRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::air_lab4::ExecuteTstRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::air_lab4::ExecuteTstRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::air_lab4::ExecuteTstRequest_<ContainerAllocator1> & lhs, const ::air_lab4::ExecuteTstRequest_<ContainerAllocator2> & rhs)
{
  return lhs.tst_file == rhs.tst_file;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::air_lab4::ExecuteTstRequest_<ContainerAllocator1> & lhs, const ::air_lab4::ExecuteTstRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace air_lab4

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::air_lab4::ExecuteTstRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::air_lab4::ExecuteTstRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::air_lab4::ExecuteTstRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::air_lab4::ExecuteTstRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::air_lab4::ExecuteTstRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::air_lab4::ExecuteTstRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::air_lab4::ExecuteTstRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "22e6d4affee3f17832329ed194a5ee94";
  }

  static const char* value(const ::air_lab4::ExecuteTstRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x22e6d4affee3f178ULL;
  static const uint64_t static_value2 = 0x32329ed194a5ee94ULL;
};

template<class ContainerAllocator>
struct DataType< ::air_lab4::ExecuteTstRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "air_lab4/ExecuteTstRequest";
  }

  static const char* value(const ::air_lab4::ExecuteTstRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::air_lab4::ExecuteTstRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string tst_file         # Name of the TST file to execute\n"
;
  }

  static const char* value(const ::air_lab4::ExecuteTstRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::air_lab4::ExecuteTstRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.tst_file);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ExecuteTstRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::air_lab4::ExecuteTstRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::air_lab4::ExecuteTstRequest_<ContainerAllocator>& v)
  {
    s << indent << "tst_file: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.tst_file);
  }
};

} // namespace message_operations
} // namespace ros

#endif // AIR_LAB4_MESSAGE_EXECUTETSTREQUEST_H
