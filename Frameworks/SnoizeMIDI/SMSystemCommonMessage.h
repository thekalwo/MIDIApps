//
//  SMSystemCommonMessage.h
//  SnoizeMIDI
//
//  Created by krevis on Sat Dec 08 2001.
//  Copyright (c) 2001 __MyCompanyName__. All rights reserved.
//

#import <SnoizeMIDI/SMMessage.h>


typedef enum _SMSystemCommonMessageType {
    SMSystemCommonMessageTypeTimeCodeQuarterFrame = 0xF1,
    SMSystemCommonMessageTypeSongPositionPointer = 0xF2,
    SMSystemCommonMessageTypeSongSelect = 0xF3,
    SMSystemCommonMessageTypeTuneRequest = 0xF6
} SMSystemCommonMessageType;

@interface SMSystemCommonMessage : SMMessage
{
    Byte dataBytes[2];
}

+ (SMSystemCommonMessage *)systemCommonMessageWithTimeStamp:(MIDITimeStamp)aTimeStamp type:(SMSystemCommonMessageType)aType data:(const Byte *)aData length:(UInt16)aLength;
    // aLength must be 0, 1, or 2

- (SMSystemCommonMessageType)type;
- (void)setType:(SMSystemCommonMessageType)newType;

- (Byte)dataByte1;
- (void)setDataByte1:(Byte)newValue;

- (Byte)dataByte2;
- (void)setDataByte2:(Byte)newValue;

@end