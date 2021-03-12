#ifndef __TYPES_H__
#define __TYPES_H__

#include <stdint.h>

#define DEBUG true

/* CONSTANT POOL */
#define CONSTANT_EMPTY                 0
#define CONSTANT_UTF8                  1
#define CONSTANT_INT                   3
#define CONSTANT_FLOAT                 4
#define CONSTANT_LONG                  5
#define CONSTANT_DOUBLE                6
#define CONSTANT_CLASS                 7
#define CONSTANT_STRING                8
#define CONSTANT_FIELD_REF             9
#define CONSTANT_METHOD_REF            10
#define CONSTANT_INTERFACE_METHOD_REF  11
#define CONSTANT_NAME_TYPE             12

/* ACCESS FLAGS */
#define ACC_PUBLIC      0x0001 // public declaration, can be accessed outside the package
#define ACC_PRIVATE     0x0002 // private declaration, restrict context to class definition
#define ACC_PROTECTED   0x0004 // protected declaration, can be used on class and subclasses
#define ACC_STATIC      0x0008 // static declaration, class variable, not instance variable
#define ACC_FINAL       0x0010 // final declaration, cannot have subclass
#define ACC_SYNCRONIZED 0x0020 // syncronized, requires a monitor before be executed (thread)
#define ACC_NATIVE      0x0100 // native, implemented in language not in Java (C, C++, Assembly)
#define ACC_VOLATILE    0x0040 // volatile declaration, cannot be in cache
#define ACC_TRANSIENT   0x0080 // transient declaration, cannot be read or write from an object persistent manager
#define ACC_SUPER       0x0020 // calls superclass methods through invoke special instruction
#define ACC_INTERFACE   0x0200 // interface, not a class
#define ACC_ABSTRACT    0x0400 // abstract declaration, cannot be instantiated
#define ACC_STRICT      0x0800 // strictfp, float point mode FP-strict (not normalized)

typedef uint8_t u1;
typedef uint16_t u2;
typedef uint32_t u4;
typedef uint64_t u8;

#endif