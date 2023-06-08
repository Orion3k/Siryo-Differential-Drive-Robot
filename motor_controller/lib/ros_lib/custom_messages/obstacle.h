#ifndef _ROS_custom_messages_obstacle_h
#define _ROS_custom_messages_obstacle_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace custom_messages
{

  class obstacle : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef float _x_velo_type;
      _x_velo_type x_velo;
      typedef float _y_velo_type;
      _y_velo_type y_velo;
      typedef float _x_radar_type;
      _x_radar_type x_radar;
      typedef float _y_radar_type;
      _y_radar_type y_radar;
      typedef float _lung_type;
      _lung_type lung;
      typedef float _larg_type;
      _larg_type larg;
      typedef float _speed_x_type;
      _speed_x_type speed_x;
      typedef float _speed_y_type;
      _speed_y_type speed_y;
      typedef int16_t _id_type;
      _id_type id;
      typedef int16_t _id_radar_type;
      _id_radar_type id_radar;
      typedef int16_t _id_velo_type;
      _id_velo_type id_velo;
      typedef int16_t _tracked_time_type;
      _tracked_time_type tracked_time;
      typedef int16_t _virtual_time_type;
      _virtual_time_type virtual_time;
      typedef const char* _obj_class_type;
      _obj_class_type obj_class;
      typedef const char* _source_type;
      _source_type source;
      typedef int16_t _probability_type;
      _probability_type probability;
      typedef int16_t _distance_type;
      _distance_type distance;

    obstacle():
      header(),
      x(0),
      y(0),
      x_velo(0),
      y_velo(0),
      x_radar(0),
      y_radar(0),
      lung(0),
      larg(0),
      speed_x(0),
      speed_y(0),
      id(0),
      id_radar(0),
      id_velo(0),
      tracked_time(0),
      virtual_time(0),
      obj_class(""),
      source(""),
      probability(0),
      distance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y);
      union {
        float real;
        uint32_t base;
      } u_x_velo;
      u_x_velo.real = this->x_velo;
      *(outbuffer + offset + 0) = (u_x_velo.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x_velo.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x_velo.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x_velo.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x_velo);
      union {
        float real;
        uint32_t base;
      } u_y_velo;
      u_y_velo.real = this->y_velo;
      *(outbuffer + offset + 0) = (u_y_velo.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y_velo.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y_velo.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y_velo.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y_velo);
      union {
        float real;
        uint32_t base;
      } u_x_radar;
      u_x_radar.real = this->x_radar;
      *(outbuffer + offset + 0) = (u_x_radar.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x_radar.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x_radar.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x_radar.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x_radar);
      union {
        float real;
        uint32_t base;
      } u_y_radar;
      u_y_radar.real = this->y_radar;
      *(outbuffer + offset + 0) = (u_y_radar.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y_radar.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y_radar.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y_radar.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y_radar);
      union {
        float real;
        uint32_t base;
      } u_lung;
      u_lung.real = this->lung;
      *(outbuffer + offset + 0) = (u_lung.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lung.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lung.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lung.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lung);
      union {
        float real;
        uint32_t base;
      } u_larg;
      u_larg.real = this->larg;
      *(outbuffer + offset + 0) = (u_larg.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_larg.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_larg.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_larg.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->larg);
      union {
        float real;
        uint32_t base;
      } u_speed_x;
      u_speed_x.real = this->speed_x;
      *(outbuffer + offset + 0) = (u_speed_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed_x);
      union {
        float real;
        uint32_t base;
      } u_speed_y;
      u_speed_y.real = this->speed_y;
      *(outbuffer + offset + 0) = (u_speed_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed_y);
      union {
        int16_t real;
        uint16_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->id);
      union {
        int16_t real;
        uint16_t base;
      } u_id_radar;
      u_id_radar.real = this->id_radar;
      *(outbuffer + offset + 0) = (u_id_radar.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id_radar.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->id_radar);
      union {
        int16_t real;
        uint16_t base;
      } u_id_velo;
      u_id_velo.real = this->id_velo;
      *(outbuffer + offset + 0) = (u_id_velo.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id_velo.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->id_velo);
      union {
        int16_t real;
        uint16_t base;
      } u_tracked_time;
      u_tracked_time.real = this->tracked_time;
      *(outbuffer + offset + 0) = (u_tracked_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tracked_time.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->tracked_time);
      union {
        int16_t real;
        uint16_t base;
      } u_virtual_time;
      u_virtual_time.real = this->virtual_time;
      *(outbuffer + offset + 0) = (u_virtual_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_virtual_time.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->virtual_time);
      uint32_t length_obj_class = strlen(this->obj_class);
      varToArr(outbuffer + offset, length_obj_class);
      offset += 4;
      memcpy(outbuffer + offset, this->obj_class, length_obj_class);
      offset += length_obj_class;
      uint32_t length_source = strlen(this->source);
      varToArr(outbuffer + offset, length_source);
      offset += 4;
      memcpy(outbuffer + offset, this->source, length_source);
      offset += length_source;
      union {
        int16_t real;
        uint16_t base;
      } u_probability;
      u_probability.real = this->probability;
      *(outbuffer + offset + 0) = (u_probability.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_probability.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->probability);
      union {
        int16_t real;
        uint16_t base;
      } u_distance;
      u_distance.real = this->distance;
      *(outbuffer + offset + 0) = (u_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->distance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        float real;
        uint32_t base;
      } u_x_velo;
      u_x_velo.base = 0;
      u_x_velo.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x_velo.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x_velo.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x_velo.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x_velo = u_x_velo.real;
      offset += sizeof(this->x_velo);
      union {
        float real;
        uint32_t base;
      } u_y_velo;
      u_y_velo.base = 0;
      u_y_velo.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y_velo.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y_velo.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y_velo.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y_velo = u_y_velo.real;
      offset += sizeof(this->y_velo);
      union {
        float real;
        uint32_t base;
      } u_x_radar;
      u_x_radar.base = 0;
      u_x_radar.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x_radar.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x_radar.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x_radar.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x_radar = u_x_radar.real;
      offset += sizeof(this->x_radar);
      union {
        float real;
        uint32_t base;
      } u_y_radar;
      u_y_radar.base = 0;
      u_y_radar.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y_radar.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y_radar.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y_radar.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y_radar = u_y_radar.real;
      offset += sizeof(this->y_radar);
      union {
        float real;
        uint32_t base;
      } u_lung;
      u_lung.base = 0;
      u_lung.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lung.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lung.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lung.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lung = u_lung.real;
      offset += sizeof(this->lung);
      union {
        float real;
        uint32_t base;
      } u_larg;
      u_larg.base = 0;
      u_larg.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_larg.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_larg.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_larg.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->larg = u_larg.real;
      offset += sizeof(this->larg);
      union {
        float real;
        uint32_t base;
      } u_speed_x;
      u_speed_x.base = 0;
      u_speed_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed_x = u_speed_x.real;
      offset += sizeof(this->speed_x);
      union {
        float real;
        uint32_t base;
      } u_speed_y;
      u_speed_y.base = 0;
      u_speed_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed_y = u_speed_y.real;
      offset += sizeof(this->speed_y);
      union {
        int16_t real;
        uint16_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id = u_id.real;
      offset += sizeof(this->id);
      union {
        int16_t real;
        uint16_t base;
      } u_id_radar;
      u_id_radar.base = 0;
      u_id_radar.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id_radar.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id_radar = u_id_radar.real;
      offset += sizeof(this->id_radar);
      union {
        int16_t real;
        uint16_t base;
      } u_id_velo;
      u_id_velo.base = 0;
      u_id_velo.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id_velo.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id_velo = u_id_velo.real;
      offset += sizeof(this->id_velo);
      union {
        int16_t real;
        uint16_t base;
      } u_tracked_time;
      u_tracked_time.base = 0;
      u_tracked_time.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tracked_time.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tracked_time = u_tracked_time.real;
      offset += sizeof(this->tracked_time);
      union {
        int16_t real;
        uint16_t base;
      } u_virtual_time;
      u_virtual_time.base = 0;
      u_virtual_time.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_virtual_time.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->virtual_time = u_virtual_time.real;
      offset += sizeof(this->virtual_time);
      uint32_t length_obj_class;
      arrToVar(length_obj_class, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_obj_class; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_obj_class-1]=0;
      this->obj_class = (char *)(inbuffer + offset-1);
      offset += length_obj_class;
      uint32_t length_source;
      arrToVar(length_source, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_source; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_source-1]=0;
      this->source = (char *)(inbuffer + offset-1);
      offset += length_source;
      union {
        int16_t real;
        uint16_t base;
      } u_probability;
      u_probability.base = 0;
      u_probability.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_probability.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->probability = u_probability.real;
      offset += sizeof(this->probability);
      union {
        int16_t real;
        uint16_t base;
      } u_distance;
      u_distance.base = 0;
      u_distance.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->distance = u_distance.real;
      offset += sizeof(this->distance);
     return offset;
    }

    virtual const char * getType() override { return "custom_messages/obstacle"; };
    virtual const char * getMD5() override { return "06c82402e1aeede7d676ec10f372fcfe"; };

  };

}
#endif
