//
//  Pixel.c
//  bitMapFilter
//
//  Created by Trevor Schmidt on 10/7/19.
//  Copyright © 2019 Trevor Schmidt. All rights reserved.
//

#include "Pixel.h"
#include <stdio.h>


void readPixelFromFile(FILE* inputFile, Pixel* thePixel){
    fscanf(inputFile, "%c%c%c", &thePixel->B, &thePixel->G, &thePixel->R);
}

void writePixelToFile(FILE* outputFile, Pixel thePixel){
    fprintf(outputFile, "%c%c%c", thePixel.B, thePixel.G, thePixel.R);
}

