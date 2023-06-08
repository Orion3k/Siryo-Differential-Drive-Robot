#ifndef _ROS_custom_messages_radar_msg_h
#define _ROS_custom_messages_radar_msg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "custom_messages/radar_point.h"

namespace custom_messages
{

  class radar_msg : public ros::Msg
  {
    public:
      uint32_t cloud_length;
      typedef custom_messages::radar_point _cloud_type;
      _cloud_type st_cloud;
      _cloud_type * cloud;
      typedef int32_t _sensor_id_type;
      _sensor_id_type sensor_id;

    radar_msg():
      cloud_length(0), st_cloud(), cloud(nullptr),
      sensor_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->cloud_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cloud_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cloud_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cloud_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cloud_length);
      for( uint32_t i = 0; i < cloud_length; i++){
      offset += this->cloud[i].serialize(outbuffer + offset);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_sensor_id;
      u_sensor_id.real = this->sensor_id;
      *(outbuffer + offset + 0) = (u_sensor_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sensor_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sensor_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sensor_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sensor_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t cloud_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cloud_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cloud_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cloud_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cloud_length);
      if(cloud_lengthT > cloud_length)
        this->cloud = (custom_messages::radar_point*)realloc(this->cloud, cloud_lengthT * sizeof(custom_messages::radar_point));
      cloud_length = cloud_lengthT;
      for( uint32_t i = 0; i < cloud_length; i++){
      offset += this->st_cloud.deserialize(inbuffer + offset);
        memcpy( &(this->cloud[i]), &(this->st_cloud), sizeof(custom_messages::radar_point));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_sensor_id;
      u_sensor_id.base = 0;
      u_sensor_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sensor_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sensor_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sensor_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sensor_id = u_sensor_id.real;
      offset += sizeof(this->sensor_id);
     return offset;
    }

    virtual const char * getType() override { return "custom_messages/radar_msg"; };
    virtual const char * getMD5() override { return "3b5f87b9539fc3c74318e4a61f36d08e"; };

  };

}
#endif
