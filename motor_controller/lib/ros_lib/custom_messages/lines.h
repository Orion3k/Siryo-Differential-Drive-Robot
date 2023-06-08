#ifndef _ROS_custom_messages_lines_h
#define _ROS_custom_messages_lines_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace custom_messages
{

  class lines : public ros::Msg
  {
    public:
      typedef float _right_a_type;
      _right_a_type right_a;
      typedef float _right_b_type;
      _right_b_type right_b;
      typedef float _right_c_type;
      _right_c_type right_c;
      typedef float _left_a_type;
      _left_a_type left_a;
      typedef float _left_b_type;
      _left_b_type left_b;
      typedef float _left_c_type;
      _left_c_type left_c;
      typedef float _distance_type;
      _distance_type distance;

    lines():
      right_a(0),
      right_b(0),
      right_c(0),
      left_a(0),
      left_b(0),
      left_c(0),
      distance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_right_a;
      u_right_a.real = this->right_a;
      *(outbuffer + offset + 0) = (u_right_a.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_a.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_a.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_a.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_a);
      union {
        float real;
        uint32_t base;
      } u_right_b;
      u_right_b.real = this->right_b;
      *(outbuffer + offset + 0) = (u_right_b.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_b.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_b.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_b.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_b);
      union {
        float real;
        uint32_t base;
      } u_right_c;
      u_right_c.real = this->right_c;
      *(outbuffer + offset + 0) = (u_right_c.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_c.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_c.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_c.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_c);
      union {
        float real;
        uint32_t base;
      } u_left_a;
      u_left_a.real = this->left_a;
      *(outbuffer + offset + 0) = (u_left_a.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_a.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_a.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_a.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_a);
      union {
        float real;
        uint32_t base;
      } u_left_b;
      u_left_b.real = this->left_b;
      *(outbuffer + offset + 0) = (u_left_b.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_b.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_b.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_b.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_b);
      union {
        float real;
        uint32_t base;
      } u_left_c;
      u_left_c.real = this->left_c;
      *(outbuffer + offset + 0) = (u_left_c.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_c.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_c.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_c.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_c);
      union {
        float real;
        uint32_t base;
      } u_distance;
      u_distance.real = this->distance;
      *(outbuffer + offset + 0) = (u_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_right_a;
      u_right_a.base = 0;
      u_right_a.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_a.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_a.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_a.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right_a = u_right_a.real;
      offset += sizeof(this->right_a);
      union {
        float real;
        uint32_t base;
      } u_right_b;
      u_right_b.base = 0;
      u_right_b.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_b.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_b.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_b.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right_b = u_right_b.real;
      offset += sizeof(this->right_b);
      union {
        float real;
        uint32_t base;
      } u_right_c;
      u_right_c.base = 0;
      u_right_c.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_c.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_c.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_c.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right_c = u_right_c.real;
      offset += sizeof(this->right_c);
      union {
        float real;
        uint32_t base;
      } u_left_a;
      u_left_a.base = 0;
      u_left_a.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_a.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_a.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_a.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left_a = u_left_a.real;
      offset += sizeof(this->left_a);
      union {
        float real;
        uint32_t base;
      } u_left_b;
      u_left_b.base = 0;
      u_left_b.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_b.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_b.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_b.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left_b = u_left_b.real;
      offset += sizeof(this->left_b);
      union {
        float real;
        uint32_t base;
      } u_left_c;
      u_left_c.base = 0;
      u_left_c.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_c.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_c.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_c.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left_c = u_left_c.real;
      offset += sizeof(this->left_c);
      union {
        float real;
        uint32_t base;
      } u_distance;
      u_distance.base = 0;
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->distance = u_distance.real;
      offset += sizeof(this->distance);
     return offset;
    }

    virtual const char * getType() override { return "custom_messages/lines"; };
    virtual const char * getMD5() override { return "f5cd9e310338a94399f43ea95b50890b"; };

  };

}
#endif
