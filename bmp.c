#include <stdio.h>

typedef struct {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BitmapFileHeader;

typedef struct {
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPixPerMeter;
    int biYPixPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} BitmapInfoHeader;

int main(void)
{
    FILE *fp;
    BitmapFileHeader fileh;
    BitmapInfoHeader infoh;
    //unsigned char BitMapOtherInfoHeader[24];
    int i;
    
    fp = fopen("bmpsample.bmp", "rb");
    
    fread(&(fileh.bfType), 2, 1, fp);
    fread(&(fileh.bfSize), 4, 1, fp);
    fread(&(fileh.bfReserved1), 2, 1, fp);
    fread(&(fileh.bfReserved2), 2, 1, fp);
    fread(&(fileh.bfOffBits), 4, 1, fp);
    fread(&(infoh.biSize), 4, 1, fp);
    fread(&(infoh.biWidth), 4, 1, fp);
    fread(&(infoh.biHeight), 4, 1, fp);
    fread(&(infoh.biPlanes), 2, 1, fp);
    fread(&(infoh.biBitCount), 2, 1, fp);
    //fread(&BitMapOtherInfoHeader,1 ,24 ,fp);
    fread(&(infoh.biCompression), 4, 1, fp);
    fread(&(infoh.biSizeImage), 4, 1, fp);
    fread(&(infoh.biXPixPerMeter), 4, 1, fp);
    fread(&(infoh.biYPixPerMeter), 4, 1, fp);
    fread(&(infoh.biClrUsed), 4, 1, fp);
    fread(&(infoh.biClrImportant), 4, 1, fp);
    fread(&i, 1,1,fp);
    
    printf("%d", i);
    
    return 0;
}

