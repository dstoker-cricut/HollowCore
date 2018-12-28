//
//  HCObject.c
//  HollowCore
//
//  Created by Matt Stoker on 12/28/18.
//  Copyright © 2018 HollowCore. All rights reserved.
//

#include "HCObject_Internal.h"

//----------------------------------------------------------------------------------------------------------------------------------
// MARK: - Memory Management
//----------------------------------------------------------------------------------------------------------------------------------
HCRef HCRetain(HCRef self) {
    // TODO: Atomic
    ((HCObjectRef)self)->referenceCount++;
    return self;
}

void HCRelease(HCRef self) {
    // TODO: Atomic
    ((HCObjectRef)self)->referenceCount--;
    if (((HCObjectRef)self)->referenceCount <= 0) {
        ((HCObjectRef)self)->type->destroy(self);
    }
}

//----------------------------------------------------------------------------------------------------------------------------------
// MARK: - Object Polymorphic Functions
//----------------------------------------------------------------------------------------------------------------------------------
HCBoolean HCIsEqual(HCRef self, HCRef other) {
    return ((HCObjectRef)self)->type->isEqual(self, other);
}

HCInteger HCHashValue(HCRef self) {
    return ((HCObjectRef)self)->type->hashValue(self);

}

void HCPrint(HCRef self, FILE* stream) {
    ((HCObjectRef)self)->type->print(self, stream);
}

//----------------------------------------------------------------------------------------------------------------------------------
// MARK: - Construction
//----------------------------------------------------------------------------------------------------------------------------------
// NOTE: Instances of HCObject should be created using sub-types

//----------------------------------------------------------------------------------------------------------------------------------
// MARK: - Object Polymorphic Functions
//----------------------------------------------------------------------------------------------------------------------------------
HCBoolean HCObjectIsEqual(HCObjectRef self, HCObjectRef other) {
    return false;
}

HCInteger HCObjectHashValue(HCObjectRef self) {
    return 0;
}

void HCObjectPrint(HCObjectRef self, FILE* stream) {
    printf("<%s> %p", self->type->name, self);
}
