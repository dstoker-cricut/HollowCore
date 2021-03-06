//
//  HCString.h
//  Test
//
//  Created by Matt Stoker on 1/17/19.
//  Copyright © 2019 HollowCore. All rights reserved.
//

#ifndef HCString_h
#define HCString_h

#include "../Core/HCObject.h"

//----------------------------------------------------------------------------------------------------------------------------------
// MARK: - Object Type
//----------------------------------------------------------------------------------------------------------------------------------
extern HCType HCStringType;
typedef struct HCString* HCStringRef;

//----------------------------------------------------------------------------------------------------------------------------------
// MARK: - Other Definitions
//----------------------------------------------------------------------------------------------------------------------------------
typedef uint8_t HCStringCodeUnit;
typedef uint32_t HCStringCodePoint;
typedef enum HCStringEncoding {
    HCStringEncodingUTF8,
    HCStringEncodingUTF16,
    HCStringEncodingUTF32
} HCStringEncoding;

//----------------------------------------------------------------------------------------------------------------------------------
// MARK: - Construction
//----------------------------------------------------------------------------------------------------------------------------------
HCStringRef HCStringCreate(void);
HCStringRef HCStringCreateWithBytes(HCStringEncoding encoding, HCInteger size, const HCByte* bytes);
HCStringRef HCStringCreateWithCString(const char* value);
HCStringRef HCStringCreateWithBoolean(HCBoolean value);
HCStringRef HCStringCreateWithInteger(HCInteger value);
HCStringRef HCStringCreateWithReal(HCReal value);

//----------------------------------------------------------------------------------------------------------------------------------
// MARK: - Object Polymorphic Functions
//----------------------------------------------------------------------------------------------------------------------------------
HCBoolean HCStringIsEqual(HCStringRef self, HCStringRef other);
HCInteger HCStringHashValue(HCStringRef self);
void HCStringPrint(HCStringRef self, FILE* stream);

//----------------------------------------------------------------------------------------------------------------------------------
// MARK: - Attributes
//----------------------------------------------------------------------------------------------------------------------------------
HCBoolean HCStringIsEmpty(HCStringRef self);
HCInteger HCStringCodeUnitCount(HCStringRef self);
HCStringCodeUnit HCStringCodeUnitAtIndex(HCStringRef self, HCInteger codeUnitIndex);
void HCStringExtractCodeUnits(HCStringRef self, HCInteger codeUnitIndex, HCInteger count, HCStringCodeUnit* destination);
HCInteger HCStringCodePointCount(HCStringRef self);
HCStringCodePoint HCStringCodePointAtIndex(HCStringRef self, HCInteger codePointIndex);
void HCStringExtractCodePoints(HCStringRef self, HCInteger codePointIndex, HCInteger count, HCStringCodePoint* destination);

//----------------------------------------------------------------------------------------------------------------------------------
// MARK: - Conversion
//----------------------------------------------------------------------------------------------------------------------------------
HCBoolean HCStringIsCString(HCStringRef self);
const char* HCStringAsCString(HCStringRef self);
HCBoolean HCStringIsBoolean(HCStringRef self);
HCBoolean HCStringAsBoolean(HCStringRef self);
HCBoolean HCStringIsInteger(HCStringRef self);
HCInteger HCStringAsInteger(HCStringRef self);
HCBoolean HCStringIsReal(HCStringRef self);
HCReal HCStringAsReal(HCStringRef self);

//----------------------------------------------------------------------------------------------------------------------------------
// MARK: - Comparison
//----------------------------------------------------------------------------------------------------------------------------------
HCBoolean HCStringIsEqualToCString(HCStringRef self, const char* string);

#endif /* HCString_h */
