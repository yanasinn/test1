#include <stdio.h>
#include <stdlib.h>

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

void change(BitmapFileHeader fileh, BitmapInfoHeader infoh, unsigned char color[][400][3], int key)
{
	FILE *fp;
	int i,j,k;
	if(key == 0){
		fp = fopen("blue.bmp", "wb");
	}else if(key == 1){
		fp = fopen("green.bmp", "wb");
	}else if(key == 2){
		fp = fopen("red.bmp", "wb");
	}
	fwrite(&fileh, 14, 1, fp);
	fwrite(&infoh, 40, 1, fp);

	for(i = 0; i < infoh.biHeight; i++){
		for(j = 0; j < infoh.biWidth; j++){
			for(k = 0; k < 3; k++){
				if(k != key){
					color[i][j][k] = 0;
				}
				fwrite(&color[i][j][k], 1, 1, fp);
			}
		}
	}	

	fclose(fp);
	return;
}

int main(void)
{
    FILE *fp;
    BitmapFileHeader fileh;
    BitmapInfoHeader infoh;

	int i,j,k, l;
	unsigned char color[300][400][3];
	unsigned char copy_color[300][400][3];
    
	fp = fopen("bmpsample.bmp", "rb");
	fread(&fileh, 14, 1, fp);
 	fread(&infoh, 40, 1, fp);

	for(i = 0; i < infoh.biHeight; i++){
		for(j = 0; j < infoh.biWidth; j++){
			for(k = 0; k < 3; k++){
				fread(&color[i][j][k], 1, 1, fp);
			}
		}
	}

	fclose(fp);

	for(l = 0; l < 3; l++){
		for(i = 0; i < infoh.biHeight; i++){
			for(j = 0; j < infoh.biWidth; j++){
				for(k = 0; k < 3; k++){
					copy_color[i][j][k] = color[i][j][k];
				}
			}
		}
		change(fileh, infoh, copy_color, l);
	}

    return 0;
}
