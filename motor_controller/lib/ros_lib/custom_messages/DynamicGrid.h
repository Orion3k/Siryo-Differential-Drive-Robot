#ifndef _ROS_custom_messages_DynamicGrid_h
#define _ROS_custom_messages_DynamicGrid_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/String.h"
#include "nav_msgs/OccupancyGrid.h"

namespace custom_messages
{

  class DynamicGrid : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef std_msgs::String _sensor_name_type;
      _sensor_name_type sensor_name;
      typedef nav_msgs::OccupancyGrid _static_grid_type;
      _static_grid_type static_grid;
      uint32_t vel_x_length;
      typedef float _vel_x_type;
      _vel_x_type st_vel_x;
      _vel_x_type * vel_x;
      uint32_t vel_y_length;
      typedef float _vel_y_type;
      _vel_y_type st_vel_y;
      _vel_y_type * vel_y;
      uint32_t obs_class_length;
      typedef int32_t _obs_class_type;
      _obs_class_type st_obs_class;
      _obs_class_type * obs_class;
      uint32_t p_A_length;
      typedef float _p_A_type;
      _p_A_type st_p_A;
      _p_A_type * p_A;
      uint32_t distance_length;
      typedef int32_t _distance_type;
      _distance_type st_distance;
      _distance_type * distance;

    DynamicGrid():
      header(),
      sensor_name(),
      static_grid(),
      vel_x_length(0), st_vel_x(), vel_x(nullptr),
      vel_y_length(0), st_vel_y(), vel_y(nullptr),
      obs_class_length(0), st_obs_class(), obs_class(nullptr),
      p_A_length(0), st_p_A(), p_A(nullptr),
      distance_length(0), st_distance(), distance(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->sensor_name.serialize(outbuffer + offset);
      offset += this->static_grid.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->vel_x_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vel_x_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->vel_x_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->vel_x_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vel_x_length);
      for( uint32_t i = 0; i < vel_x_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->vel_x[i]);
      }
      *(outbuffer + offset + 0) = (this->vel_y_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vel_y_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->vel_y_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->vel_y_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vel_y_length);
      for( uint32_t i = 0; i < vel_y_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->vel_y[i]);
      }
      *(outbuffer + offset + 0) = (this->obs_class_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->obs_class_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->obs_class_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->obs_class_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obs_class_length);
      for( uint32_t i = 0; i < obs_class_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_obs_classi;
      u_obs_classi.real = this->obs_class[i];
      *(outbuffer + offset + 0) = (u_obs_classi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obs_classi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obs_classi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obs_classi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obs_class[i]);
      }
      *(outbuffer + offset + 0) = (this->p_A_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->p_A_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->p_A_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->p_A_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->p_A_length);
      for( uint32_t i = 0; i < p_A_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->p_A[i]);
      }
      *(outbuffer + offset + 0) = (this->distance_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->distance_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->distance_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->distance_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance_length);
      for( uint32_t i = 0; i < distance_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_distancei;
      u_distancei.real = this->distance[i];
      *(outbuffer + offset + 0) = (u_distancei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distancei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distancei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distancei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->sensor_name.deserialize(inbuffer + offset);
      offset += this->static_grid.deserialize(inbuffer + offset);
      uint32_t vel_x_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      vel_x_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      vel_x_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      vel_x_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->vel_x_length);
      if(vel_x_lengthT > vel_x_length)
        this->vel_x = (float*)realloc(this->vel_x, vel_x_lengthT * sizeof(float));
      vel_x_length = vel_x_lengthT;
      for( uint32_t i = 0; i < vel_x_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_vel_x));
        memcpy( &(this->vel_x[i]), &(this->st_vel_x), sizeof(float));
      }
      uint32_t vel_y_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      vel_y_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      vel_y_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      vel_y_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->vel_y_length);
      if(vel_y_lengthT > vel_y_length)
        this->vel_y = (float*)realloc(this->vel_y, vel_y_lengthT * sizeof(float));
      vel_y_length = vel_y_lengthT;
      for( uint32_t i = 0; i < vel_y_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_vel_y));
        memcpy( &(this->vel_y[i]), &(this->st_vel_y), sizeof(float));
      }
      uint32_t obs_class_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      obs_class_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      obs_class_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      obs_class_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->obs_class_length);
      if(obs_class_lengthT > obs_class_length)
        this->obs_class = (int32_t*)realloc(this->obs_class, obs_class_lengthT * sizeof(int32_t));
      obs_class_length = obs_class_lengthT;
      for( uint32_t i = 0; i < obs_class_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_obs_class;
      u_st_obs_class.base = 0;
      u_st_obs_class.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_obs_class.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_obs_class.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_obs_class.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_obs_class = u_st_obs_class.real;
      offset += sizeof(this->st_obs_class);
        memcpy( &(this->obs_class[i]), &(this->st_obs_class), sizeof(int32_t));
      }
      uint32_t p_A_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      p_A_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      p_A_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      p_A_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->p_A_length);
      if(p_A_lengthT > p_A_length)
        this->p_A = (float*)realloc(this->p_A, p_A_lengthT * sizeof(float));
      p_A_length = p_A_lengthT;
      for( uint32_t i = 0; i < p_A_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_p_A));
        memcpy( &(this->p_A[i]), &(this->st_p_A), sizeof(float));
      }
      uint32_t distance_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      distance_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      distance_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      distance_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->distance_length);
      if(distance_lengthT > distance_length)
        this->distance = (int32_t*)realloc(this->distance, distance_lengthT * sizeof(int32_t));
      distance_length = distance_lengthT;
      for( uint32_t i = 0; i < distance_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_distance;
      u_st_distance.base = 0;
      u_st_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_distance = u_st_distance.real;
      offset += sizeof(this->st_distance);
        memcpy( &(this->distance[i]), &(this->st_distance), sizeof(int32_t));
      }
     return offset;
    }

    virtual const char * getType() override { return "custom_messages/DynamicGrid"; };
    virtual const char * getMD5() override { return "a918c588e384c03709492c1f724156c1"; };

  };

}
#endif
