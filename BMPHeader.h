//
//  BMPHeader.h
//  bitMapFilter
//
//  Created by Trevor Schmidt on 10/7/19.
//  Copyright © 2019 Trevor Schmidt. All rights reserved.
//

#ifndef BMPHeader_h
#define BMPHeader_h

#include <stdio.h>

#define BMPHEADER_SIZE 14

typedef struct{
    unsigned char headerField[2];
    unsigned int fileSize;
    unsigned int reservedBytes;
    unsigned int pixelArrayOffset;
}BMPHeader;

void readBMPHeaderFromFile(FILE* inputFile, BMPHeader* theHeader);
void writeBMPHeaderToFile(FILE* outputFile, BMPHeader theHeader);

#endif /* BMPHeader_h */
