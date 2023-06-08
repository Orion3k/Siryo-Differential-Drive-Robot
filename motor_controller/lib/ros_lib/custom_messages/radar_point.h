#ifndef _ROS_custom_messages_radar_point_h
#define _ROS_custom_messages_radar_point_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace custom_messages
{

  class radar_point : public ros::Msg
  {
    public:
      typedef int16_t _obj_ID_type;
      _obj_ID_type obj_ID;
      typedef float _obj_dist_long_type;
      _obj_dist_long_type obj_dist_long;
      typedef float _obj_dist_lat_type;
      _obj_dist_lat_type obj_dist_lat;
      typedef float _obj_vrel_long_type;
      _obj_vrel_long_type obj_vrel_long;
      typedef float _obj_vrel_lat_type;
      _obj_vrel_lat_type obj_vrel_lat;
      typedef int16_t _obj_dynamics_type;
      _obj_dynamics_type obj_dynamics;
      typedef float _obj_RCS_type;
      _obj_RCS_type obj_RCS;
      typedef int16_t _obj_ID_c_type;
      _obj_ID_c_type obj_ID_c;
      typedef int16_t _obj_dist_long_rms_type;
      _obj_dist_long_rms_type obj_dist_long_rms;
      typedef int16_t _obj_dist_lat_rms_type;
      _obj_dist_lat_rms_type obj_dist_lat_rms;
      typedef int16_t _obj_vrel_long_rms_type;
      _obj_vrel_long_rms_type obj_vrel_long_rms;
      typedef int16_t _obj_vrel_lat_rms_type;
      _obj_vrel_lat_rms_type obj_vrel_lat_rms;
      typedef int16_t _obj_arel_long_rms_type;
      _obj_arel_long_rms_type obj_arel_long_rms;
      typedef int16_t _obj_arel_lat_rms_type;
      _obj_arel_lat_rms_type obj_arel_lat_rms;
      typedef int16_t _obj_heading_rms_type;
      _obj_heading_rms_type obj_heading_rms;
      typedef int16_t _obj_state_type;
      _obj_state_type obj_state;
      typedef int16_t _obj_probability_type;
      _obj_probability_type obj_probability;
      typedef int16_t _obj_ID_d_type;
      _obj_ID_d_type obj_ID_d;
      typedef float _obj_arel_long_type;
      _obj_arel_long_type obj_arel_long;
      typedef float _obj_arel_lat_type;
      _obj_arel_lat_type obj_arel_lat;
      typedef int16_t _obj_class_type;
      _obj_class_type obj_class;
      typedef float _obj_heading_type;
      _obj_heading_type obj_heading;
      typedef float _obj_length_type;
      _obj_length_type obj_length;
      typedef float _obj_width_type;
      _obj_width_type obj_width;

    radar_point():
      obj_ID(0),
      obj_dist_long(0),
      obj_dist_lat(0),
      obj_vrel_long(0),
      obj_vrel_lat(0),
      obj_dynamics(0),
      obj_RCS(0),
      obj_ID_c(0),
      obj_dist_long_rms(0),
      obj_dist_lat_rms(0),
      obj_vrel_long_rms(0),
      obj_vrel_lat_rms(0),
      obj_arel_long_rms(0),
      obj_arel_lat_rms(0),
      obj_heading_rms(0),
      obj_state(0),
      obj_probability(0),
      obj_ID_d(0),
      obj_arel_long(0),
      obj_arel_lat(0),
      obj_class(0),
      obj_heading(0),
      obj_length(0),
      obj_width(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_obj_ID;
      u_obj_ID.real = this->obj_ID;
      *(outbuffer + offset + 0) = (u_obj_ID.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_ID.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->obj_ID);
      union {
        float real;
        uint32_t base;
      } u_obj_dist_long;
      u_obj_dist_long.real = this->obj_dist_long;
      *(outbuffer + offset + 0) = (u_obj_dist_long.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_dist_long.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obj_dist_long.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obj_dist_long.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obj_dist_long);
      union {
        float real;
        uint32_t base;
      } u_obj_dist_lat;
      u_obj_dist_lat.real = this->obj_dist_lat;
      *(outbuffer + offset + 0) = (u_obj_dist_lat.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_dist_lat.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obj_dist_lat.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obj_dist_lat.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obj_dist_lat);
      union {
        float real;
        uint32_t base;
      } u_obj_vrel_long;
      u_obj_vrel_long.real = this->obj_vrel_long;
      *(outbuffer + offset + 0) = (u_obj_vrel_long.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_vrel_long.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obj_vrel_long.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obj_vrel_long.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obj_vrel_long);
      union {
        float real;
        uint32_t base;
      } u_obj_vrel_lat;
      u_obj_vrel_lat.real = this->obj_vrel_lat;
      *(outbuffer + offset + 0) = (u_obj_vrel_lat.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_vrel_lat.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obj_vrel_lat.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obj_vrel_lat.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obj_vrel_lat);
      union {
        int16_t real;
        uint16_t base;
      } u_obj_dynamics;
      u_obj_dynamics.real = this->obj_dynamics;
      *(outbuffer + offset + 0) = (u_obj_dynamics.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_dynamics.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->obj_dynamics);
      union {
        float real;
        uint32_t base;
      } u_obj_RCS;
      u_obj_RCS.real = this->obj_RCS;
      *(outbuffer + offset + 0) = (u_obj_RCS.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_RCS.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obj_RCS.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obj_RCS.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obj_RCS);
      union {
        int16_t real;
        uint16_t base;
      } u_obj_ID_c;
      u_obj_ID_c.real = this->obj_ID_c;
      *(outbuffer + offset + 0) = (u_obj_ID_c.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_ID_c.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->obj_ID_c);
      union {
        int16_t real;
        uint16_t base;
      } u_obj_dist_long_rms;
      u_obj_dist_long_rms.real = this->obj_dist_long_rms;
      *(outbuffer + offset + 0) = (u_obj_dist_long_rms.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_dist_long_rms.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->obj_dist_long_rms);
      union {
        int16_t real;
        uint16_t base;
      } u_obj_dist_lat_rms;
      u_obj_dist_lat_rms.real = this->obj_dist_lat_rms;
      *(outbuffer + offset + 0) = (u_obj_dist_lat_rms.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_dist_lat_rms.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->obj_dist_lat_rms);
      union {
        int16_t real;
        uint16_t base;
      } u_obj_vrel_long_rms;
      u_obj_vrel_long_rms.real = this->obj_vrel_long_rms;
      *(outbuffer + offset + 0) = (u_obj_vrel_long_rms.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_vrel_long_rms.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->obj_vrel_long_rms);
      union {
        int16_t real;
        uint16_t base;
      } u_obj_vrel_lat_rms;
      u_obj_vrel_lat_rms.real = this->obj_vrel_lat_rms;
      *(outbuffer + offset + 0) = (u_obj_vrel_lat_rms.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_vrel_lat_rms.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->obj_vrel_lat_rms);
      union {
        int16_t real;
        uint16_t base;
      } u_obj_arel_long_rms;
      u_obj_arel_long_rms.real = this->obj_arel_long_rms;
      *(outbuffer + offset + 0) = (u_obj_arel_long_rms.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_arel_long_rms.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->obj_arel_long_rms);
      union {
        int16_t real;
        uint16_t base;
      } u_obj_arel_lat_rms;
      u_obj_arel_lat_rms.real = this->obj_arel_lat_rms;
      *(outbuffer + offset + 0) = (u_obj_arel_lat_rms.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_arel_lat_rms.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->obj_arel_lat_rms);
      union {
        int16_t real;
        uint16_t base;
      } u_obj_heading_rms;
      u_obj_heading_rms.real = this->obj_heading_rms;
      *(outbuffer + offset + 0) = (u_obj_heading_rms.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_heading_rms.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->obj_heading_rms);
      union {
        int16_t real;
        uint16_t base;
      } u_obj_state;
      u_obj_state.real = this->obj_state;
      *(outbuffer + offset + 0) = (u_obj_state.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_state.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->obj_state);
      union {
        int16_t real;
        uint16_t base;
      } u_obj_probability;
      u_obj_probability.real = this->obj_probability;
      *(outbuffer + offset + 0) = (u_obj_probability.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_probability.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->obj_probability);
      union {
        int16_t real;
        uint16_t base;
      } u_obj_ID_d;
      u_obj_ID_d.real = this->obj_ID_d;
      *(outbuffer + offset + 0) = (u_obj_ID_d.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_ID_d.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->obj_ID_d);
      union {
        float real;
        uint32_t base;
      } u_obj_arel_long;
      u_obj_arel_long.real = this->obj_arel_long;
      *(outbuffer + offset + 0) = (u_obj_arel_long.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_arel_long.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obj_arel_long.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obj_arel_long.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obj_arel_long);
      union {
        float real;
        uint32_t base;
      } u_obj_arel_lat;
      u_obj_arel_lat.real = this->obj_arel_lat;
      *(outbuffer + offset + 0) = (u_obj_arel_lat.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_arel_lat.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obj_arel_lat.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obj_arel_lat.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obj_arel_lat);
      union {
        int16_t real;
        uint16_t base;
      } u_obj_class;
      u_obj_class.real = this->obj_class;
      *(outbuffer + offset + 0) = (u_obj_class.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_class.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->obj_class);
      union {
        float real;
        uint32_t base;
      } u_obj_heading;
      u_obj_heading.real = this->obj_heading;
      *(outbuffer + offset + 0) = (u_obj_heading.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_heading.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obj_heading.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obj_heading.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obj_heading);
      union {
        float real;
        uint32_t base;
      } u_obj_length;
      u_obj_length.real = this->obj_length;
      *(outbuffer + offset + 0) = (u_obj_length.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_length.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obj_length.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obj_length.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obj_length);
      union {
        float real;
        uint32_t base;
      } u_obj_width;
      u_obj_width.real = this->obj_width;
      *(outbuffer + offset + 0) = (u_obj_width.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_width.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obj_width.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obj_width.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obj_width);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_obj_ID;
      u_obj_ID.base = 0;
      u_obj_ID.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obj_ID.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->obj_ID = u_obj_ID.real;
      offset += sizeof(this->obj_ID);
      union {
        float real;
        uint32_t base;
      } u_obj_dist_long;
      u_obj_dist_long.base = 0;
      u_obj_dist_long.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obj_dist_long.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_obj_dist_long.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_obj_dist_long.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->obj_dist_long = u_obj_dist_long.real;
      offset += sizeof(this->obj_dist_long);
      union {
        float real;
        uint32_t base;
      } u_obj_dist_lat;
      u_obj_dist_lat.base = 0;
      u_obj_dist_lat.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obj_dist_lat.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_obj_dist_lat.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_obj_dist_lat.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->obj_dist_lat = u_obj_dist_lat.real;
      offset += sizeof(this->obj_dist_lat);
      union {
        float real;
        uint32_t base;
      } u_obj_vrel_long;
      u_obj_vrel_long.base = 0;
      u_obj_vrel_long.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obj_vrel_long.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_obj_vrel_long.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_obj_vrel_long.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->obj_vrel_long = u_obj_vrel_long.real;
      offset += sizeof(this->obj_vrel_long);
      union {
        float real;
        uint32_t base;
      } u_obj_vrel_lat;
      u_obj_vrel_lat.base = 0;
      u_obj_vrel_lat.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obj_vrel_lat.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_obj_vrel_lat.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_obj_vrel_lat.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->obj_vrel_lat = u_obj_vrel_lat.real;
      offset += sizeof(this->obj_vrel_lat);
      union {
        int16_t real;
        uint16_t base;
      } u_obj_dynamics;
      u_obj_dynamics.base = 0;
      u_obj_dynamics.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obj_dynamics.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->obj_dynamics = u_obj_dynamics.real;
      offset += sizeof(this->obj_dynamics);
      union {
        float real;
        uint32_t base;
      } u_obj_RCS;
      u_obj_RCS.base = 0;
      u_obj_RCS.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obj_RCS.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_obj_RCS.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_obj_RCS.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->obj_RCS = u_obj_RCS.real;
      offset += sizeof(this->obj_RCS);
      union {
        int16_t real;
        uint16_t base;
      } u_obj_ID_c;
      u_obj_ID_c.base = 0;
      u_obj_ID_c.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obj_ID_c.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->obj_ID_c = u_obj_ID_c.real;
      offset += sizeof(this->obj_ID_c);
      union {
        int16_t real;
        uint16_t base;
      } u_obj_dist_long_rms;
      u_obj_dist_long_rms.base = 0;
      u_obj_dist_long_rms.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obj_dist_long_rms.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->obj_dist_long_rms = u_obj_dist_long_rms.real;
      offset += sizeof(this->obj_dist_long_rms);
      union {
        int16_t real;
        uint16_t base;
      } u_obj_dist_lat_rms;
      u_obj_dist_lat_rms.base = 0;
      u_obj_dist_lat_rms.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obj_dist_lat_rms.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->obj_dist_lat_rms = u_obj_dist_lat_rms.real;
      offset += sizeof(this->obj_dist_lat_rms);
      union {
        int16_t real;
        uint16_t base;
      } u_obj_vrel_long_rms;
      u_obj_vrel_long_rms.base = 0;
      u_obj_vrel_long_rms.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obj_vrel_long_rms.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->obj_vrel_long_rms = u_obj_vrel_long_rms.real;
      offset += sizeof(this->obj_vrel_long_rms);
      union {
        int16_t real;
        uint16_t base;
      } u_obj_vrel_lat_rms;
      u_obj_vrel_lat_rms.base = 0;
      u_obj_vrel_lat_rms.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obj_vrel_lat_rms.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->obj_vrel_lat_rms = u_obj_vrel_lat_rms.real;
      offset += sizeof(this->obj_vrel_lat_rms);
      union {
        int16_t real;
        uint16_t base;
      } u_obj_arel_long_rms;
      u_obj_arel_long_rms.base = 0;
      u_obj_arel_long_rms.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obj_arel_long_rms.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->obj_arel_long_rms = u_obj_arel_long_rms.real;
      offset += sizeof(this->obj_arel_long_rms);
      union {
        int16_t real;
        uint16_t base;
      } u_obj_arel_lat_rms;
      u_obj_arel_lat_rms.base = 0;
      u_obj_arel_lat_rms.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obj_arel_lat_rms.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->obj_arel_lat_rms = u_obj_arel_lat_rms.real;
      offset += sizeof(this->obj_arel_lat_rms);
      union {
        int16_t real;
        uint16_t base;
      } u_obj_heading_rms;
      u_obj_heading_rms.base = 0;
      u_obj_heading_rms.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obj_heading_rms.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->obj_heading_rms = u_obj_heading_rms.real;
      offset += sizeof(this->obj_heading_rms);
      union {
        int16_t real;
        uint16_t base;
      } u_obj_state;
      u_obj_state.base = 0;
      u_obj_state.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obj_state.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->obj_state = u_obj_state.real;
      offset += sizeof(this->obj_state);
      union {
        int16_t real;
        uint16_t base;
      } u_obj_probability;
      u_obj_probability.base = 0;
      u_obj_probability.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obj_probability.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->obj_probability = u_obj_probability.real;
      offset += sizeof(this->obj_probability);
      union {
        int16_t real;
        uint16_t base;
      } u_obj_ID_d;
      u_obj_ID_d.base = 0;
      u_obj_ID_d.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obj_ID_d.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->obj_ID_d = u_obj_ID_d.real;
      offset += sizeof(this->obj_ID_d);
      union {
        float real;
        uint32_t base;
      } u_obj_arel_long;
      u_obj_arel_long.base = 0;
      u_obj_arel_long.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obj_arel_long.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_obj_arel_long.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_obj_arel_long.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->obj_arel_long = u_obj_arel_long.real;
      offset += sizeof(this->obj_arel_long);
      union {
        float real;
        uint32_t base;
      } u_obj_arel_lat;
      u_obj_arel_lat.base = 0;
      u_obj_arel_lat.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obj_arel_lat.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_obj_arel_lat.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_obj_arel_lat.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->obj_arel_lat = u_obj_arel_lat.real;
      offset += sizeof(this->obj_arel_lat);
      union {
        int16_t real;
        uint16_t base;
      } u_obj_class;
      u_obj_class.base = 0;
      u_obj_class.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obj_class.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->obj_class = u_obj_class.real;
      offset += sizeof(this->obj_class);
      union {
        float real;
        uint32_t base;
      } u_obj_heading;
      u_obj_heading.base = 0;
      u_obj_heading.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obj_heading.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_obj_heading.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_obj_heading.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->obj_heading = u_obj_heading.real;
      offset += sizeof(this->obj_heading);
      union {
        float real;
        uint32_t base;
      } u_obj_length;
      u_obj_length.base = 0;
      u_obj_length.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obj_length.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_obj_length.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_obj_length.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->obj_length = u_obj_length.real;
      offset += sizeof(this->obj_length);
      union {
        float real;
        uint32_t base;
      } u_obj_width;
      u_obj_width.base = 0;
      u_obj_width.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obj_width.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_obj_width.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_obj_width.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->obj_width = u_obj_width.real;
      offset += sizeof(this->obj_width);
     return offset;
    }

    virtual const char * getType() override { return "custom_messages/radar_point"; };
    virtual const char * getMD5() override { return "5bdeafc12ca433d80f98b1cf41d8fc64"; };

  };

}
#endif
