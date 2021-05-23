/**
 * @file JsonAsyncComm.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __JSONASYNCCOMM__H__
#define __JSONASYNCCOMM__H__

#include "JsonAsyncComm.hpp"

#define setVariable(variable, value) updateValueByKey(#variable, value)
#define getVariable(variable) updateValueByKey(#variable, &variable)

#endif  //!__JSONASYNCCOMM__H__