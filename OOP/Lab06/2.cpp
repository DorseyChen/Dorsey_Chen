#include<stdio.h>
#include<stdlib.h>

struct FileHeader{
	unsigned int size;
	unsigned int offset;
};

struct FileInfo{
	unsigned int size;
	int width, height;
	unsigned short int bits;
	unsigned int imagesize;
};

void readFileHeader(FILE *fp, struct FileHeader* fh){
	int x;
	fseek(fp, 2, SEEK_SET);
	fread(&x, 4, 1, fp);
	fh->size=x;
	fseek(fp, 10, SEEK_SET);
	fread(&x, 4, 1, fp);
	fh->offset=x;
}

void printFileHeader(struct FileHeader fh){
	printf("====== File Header ======\n");
	printf("File size: %d\n",fh.size);
	printf("Image offset: %d\n",fh.offset);
}

void readFileInfo(FILE *fp, struct FileInfo *fi){
	int x;
	fseek(fp, 14, SEEK_SET);
	fread(&x, 4, 1, fp);
	fi->size=x;
	fseek(fp, 18, SEEK_SET);
	fread(&x, 4, 1, fp);
	fi->width=x;
	fseek(fp, 22, SEEK_SET);
	fread(&x, 4, 1, fp);
	fi->height=x;
	fseek(fp, 28, SEEK_SET);
	fread(&x, 2, 1, fp);
	fi->bits=x;
	fseek(fp, 34, SEEK_SET);
	fread(&x, 4, 1, fp);
	fi->imagesize=x;
}

void printFileInfo(struct FileInfo fi){
	printf("====== File Info======\n");
	printf("Info size: %d\n", fi.size);
	printf("Number of pixels: %d * %d\n", fi.width, fi.height);
	printf("Bits per pixel: %d\n", fi.bits);
}

void createImage(int w, int h, unsigned char**** image){
	int i, j;
	*image=new unsigned char **[h];
	if(h<0)
		h=-h;
	for(i=0; i<h; i++){
		*image[i]=new unsigned char *[w];
		for(j=0; j<w; j++)
			*image[i][j]=new unsigned char [3];
	}
}

void readImage(FILE *fp, unsigned int offset, int w, int h, unsigned char ***image){
	int i, j, k;
	char x;
	fseek(fp, offset, SEEK_SET);
	
	if(h<0)
		for(i=0; i<-h; i++)
			for(j=0; j<w; j++)
				for(k=2; k>=0; k--)
					fread(&image[i][j][k], 1, 1, fp);
	else
		for(i=h; i>=0; i--)
			for(j=0; j<w; j++)
				for(k=2; k>=0; k--)
					fread(&image[i][j][k], 1, 1, fp);
}

void showImage(int w, int h, unsigned char*** image){
	w=abs(w);
	h=abs(h);
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			unsigned char r=image[i][j][0], g=image[i][j][1],b=image[i][j][2];
			printf("\e[48;5;");
			unsigned int num=16+36*(r/43)+6*(g/43)+(b/43);
			printf("%d",num);
			printf("m  \e[0m");
		}
		printf("\n");
	}
}

int main(int argc, char* argv[]){
	// read file
	FILE *fp;
	if((fp=fopen(argv[1], "rb"))==NULL){
		printf("Cannot open the file. \n");
		exit(1);
	}
	// ........
	if(fp) {
		// (1)
		struct FileHeader fheader;
		readFileHeader(fp, &fheader);
		printFileHeader(fheader);
		// (2)
		struct FileInfo fInfo;
		readFileInfo(fp, &fInfo);
		printFileInfo(fInfo);
		// (3)
		unsigned char ***rawImage; // each pixel has R,G,B
		createImage(fInfo.width, fInfo.height, &rawImage);
		readImage(fp, fheader.offset, fInfo.width, fInfo.height, rawImage);
		showImage(fInfo.width, fInfo.height, rawImage);
	} else {
		printf("File open failed!\n");
	}
	return 0;
}
