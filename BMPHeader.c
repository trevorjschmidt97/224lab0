//
//  BMPHeader.c
//  bitMapFilter
//
//  Created by Trevor Schmidt on 10/7/19.
//  Copyright © 2019 Trevor Schmidt. All rights reserved.
//

#include "BMPHeader.h"
#include <stdio.h>

void readBMPHeaderFromFile(FILE* inputFile, BMPHeader* theHeader)
{
    fread(theHeader->headerField, 2, 1, inputFile);
    fread(&theHeader->fileSize, 4, 1, inputFile);
    fread(&theHeader->reservedBytes, 4, 1, inputFile);
    fread(&theHeader->pixelArrayOffset, 4, 1, inputFile);
}


void writeBMPHeaderToFile(FILE* outputFile, BMPHeader theHeader)
{
    fwrite(theHeader.headerField, 2, 1, outputFile);
    fwrite(&theHeader.fileSize, 4, 1, outputFile);
    fwrite(&theHeader.reservedBytes, 4, 1, outputFile);
    fwrite(&theHeader.pixelArrayOffset, 4, 1, outputFile);
}
