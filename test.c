#include <stdint.h>
#include <stdio.h>
#include <malloc.h>

#define REDS     "\x1b[31m"
#define GREENS   "\x1b[32m"
#define NORMALS  "\x1b[0m"

#define IMAGE unsigned char ***
#define RED 0
#define GREEN 1
#define BLUE 2

#define WIDTH 640
#define HEIGHT 480

int **init_space(int height, int width);

#include "student_code.c"

unsigned char **init_chanel();
unsigned char ***init_image();
static void readBmp(char *filename, IMAGE image);

int main() {
	bool success = true;
	
	char filename1[] = "Labs/Lab5/line1.bmp";
	IMAGE image1 = init_image();
	readBmp(filename1, image1);
	float m1_gold = -0.7 ,b1_gold = 406;
	float m1 = 0 ,b1 = 0;
	detect_line(image1, &m1, &b1);
	printf("Line 1 results :\n");
	if (m1_gold - .1 < m1 && m1_gold + .1 > m1)
	{
		printf("m: %f (%sSUCCESS%s)\n", m1, GREENS, NORMALS);	
	}
	else
	{
		success = false;
		printf("m: %f (%sFAIL%s) expected %f\n", m1, REDS, NORMALS, m1_gold);
	}	
	if (b1_gold - 4 < b1 && b1_gold + 4 > b1)
	{
		printf("b: %f (%sSUCCESS%s)\n", b1, GREENS, NORMALS);	
	}
	else
	{
		success = false;
		printf("b: %f (%sFAIL%s) expected %f\n", b1, REDS, NORMALS , b1_gold);
	}	
	printf("\n");

	char filename2[] = "Labs/Lab5/line2.bmp";
	IMAGE image2 = init_image();
	readBmp(filename2, image2);
	float m2_gold = -1.55 ,b2_gold = 561;
	float m2 = 0 ,b2 = 0;
	detect_line(image2, &m2, &b2);
	printf("Line 2 results :\n");
	if (m2_gold - .1 < m2 && m2_gold + .1 > m2)
	{
		printf("m: %f (%sSUCCESS%s)\n", m2, GREENS, NORMALS);	
	}
	else
	{
		success = false;
		printf("m: %f (%sFAIL%s) expected %f\n", m2, REDS, NORMALS, m2_gold);
	}
	if (b2_gold - 5 < b2 && b2_gold + 5 > b2)
	{
		printf("b: %f (%sSUCCESS%s)\n", b2, GREENS, NORMALS);	
	}
	else
	{
		success = false;
		printf("b: %f (%sFAIL%s) expected %f\n", b2, REDS, NORMALS , b2_gold);
	}	
	printf("\n");

	char filename3[] = "Labs/Lab5/line3.bmp";
	IMAGE image3 = init_image();
	readBmp(filename3, image3);
	float m3_gold = .33 ,b3_gold = 30;
	float m3 = 0 ,b3 = 0;
	detect_line(image3, &m3, &b3);
	printf("Line 3 results :\n");
	if (m3_gold - .1 < m3 && m3_gold + .1 > m3)
	{
		printf("m: %f (%sSUCCESS%s)\n", m3, GREENS, NORMALS);	
	}
	else
	{
		success = false;
		printf("m: %f (%sFAIL%s) expected %f\n", m3, REDS, NORMALS, m3_gold);
	}	
	if (b3_gold - 2 < b3 && b3_gold + 2 > b3)
	{
		printf("b: %f (%sSUCCESS%s)\n", b3, GREENS, NORMALS);	
	}
	else
	{
		success = false;
		printf("b: %f (%sFAIL%s) expected %f\n", b3, REDS, NORMALS , b3_gold);
	}	
	printf("\n");
	
	char filename4[] = "Labs/Lab5/line4.bmp";
	IMAGE image4 = init_image();
	readBmp(filename4, image4);
	float m4_gold = .73 ,b4_gold = 26;
	float m4 = 0 ,b4 = 0;
	detect_line(image4, &m4, &b4);
	printf("Line 4 results :\n");
	if (m4_gold - .1 < m4 && m4_gold + .1 > m4)
	{
		printf("m: %f (%sSUCCESS%s)\n", m4, GREENS, NORMALS);	
	}
	else
	{
		success = false;
		printf("m: %f (%sFAIL%s) expected %f\n", m4, REDS, NORMALS, m4_gold);
	}	
	if (b4_gold - 2 < b4 && b4_gold + 2 > b4)
	{
		printf("b: %f (%sSUCCESS%s)\n", b4, GREENS, NORMALS);	
	}
	else
	{
		success = false;
		printf("b: %f (%sFAIL%s) expected %f\n", b4, REDS, NORMALS , b4_gold);
	}	
	printf("\n");
	
	char filenamep1[] = "Labs/Lab5/poly1.bmp";
	IMAGE imagep1 = init_image();
	readBmp(filenamep1, imagep1);
	int poly1=detect_polygon(imagep1);
	printf("Polygon 1 results :\n");
	if (poly1 == 5)
	{
		printf("sides: %d (%sSUCCESS%s)\n", poly1, GREENS, NORMALS);	
	}
	else
	{
		success = false;
		printf("sides: %d (%sFAIL%s) expected %d\n", poly1, REDS, NORMALS, 5);
	}	
	printf("\n");

	char filenamep2[] = "Labs/Lab5/poly2.bmp";
	IMAGE imagep2 = init_image();
	readBmp(filenamep2, imagep2);
	int poly2=detect_polygon(imagep2);
	printf("Polygon 2 results :\n");
	if (poly2 == 6)
	{
		printf("sides: %d (%sSUCCESS%s)\n", poly2, GREENS, NORMALS);	
	}
	else
	{
		success = false;
		printf("sides: %d (%sFAIL%s) expected %d\n", poly2, REDS, NORMALS, 6);
	}	
	printf("\n");

	char filenamep3[] = "Labs/Lab5/poly3.bmp";
	IMAGE imagep3 = init_image();
	readBmp(filenamep3, imagep3);
	int poly3=detect_polygon(imagep3);
	printf("Polygon 3 results :\n");
	if (poly3 == 5)
	{
		printf("sides: %d (%sSUCCESS%s)\n", poly3, GREENS, NORMALS);	
	}
	else
	{
		success = false;
		printf("sides: %d (%sFAIL%s) expected %d\n", poly3, REDS, NORMALS, 6);
	}	
	printf("\n");
	
	char filenamep4[] = "Labs/Lab5/poly4.bmp";
	IMAGE imagep4 = init_image();
	readBmp(filenamep4, imagep4);
	int poly4=detect_polygon(imagep4);
	printf("Polygon 4 results :\n");
	if (poly4 == 3)
	{
		printf("sides: %d (%sSUCCESS%s)\n", poly4, GREENS, NORMALS);	
	}
	else
	{
		success = false;
		printf("sides: %d (%sFAIL%s) expected %d\n", poly4, REDS, NORMALS, 3);
	}	
	printf("\n");

	char filenamec1[] = "Labs/Lab5/circle1.bmp";
	IMAGE imagec1 = init_image();
	readBmp(filenamec1, imagec1);
	int circle1=circle_on_top(imagec1);
	printf("Robot Experiment 1 results :\n");
	if (circle1 == BLUE)
	{
		printf("winner: BLUE (%sSUCCESS%s)\n", GREENS, NORMALS);	
	}
	else
	{
		success = false;
		printf("winner: RED (%sFAIL%s) expected BLUE\n", REDS, NORMALS);
	}	
	printf("\n");
	
	char filenamec2[] = "Labs/Lab5/circle2.bmp";
	IMAGE imagec2 = init_image();
	readBmp(filenamec2, imagec2);
	int circle2=circle_on_top(imagec2);
	printf("Robot Experiment 2 results :\n");
	if (circle2 == BLUE)
	{
		printf("winner: BLUE (%sSUCCESS%s)\n", GREENS, NORMALS);	
	}
	else
	{
		success = false;
		printf("winner: RED (%sFAIL%s) expected BLUE\n", REDS, NORMALS);
	}	
	printf("\n");

	char filenamec3[] = "Labs/Lab5/circle3.bmp";
	IMAGE imagec3 = init_image();
	readBmp(filenamec3, imagec3);
	int circle3=circle_on_top(imagec3);
	printf("Robot Experiment 3 results :\n");
	if (circle3 == RED)
	{
		printf("winner: RED (%sSUCCESS%s)\n", GREENS, NORMALS);	
	}
	else
	{
		success = false;
		printf("winner: BLUE (%sFAIL%s) expected BLUE\n", REDS, NORMALS);
	}	
	printf("\n");

    return !success;
}

unsigned char ***init_image()
{
	IMAGE image;
	image = (unsigned char ***) malloc(sizeof(unsigned char**)*3);
	image[RED]=init_chanel();
	image[GREEN]=init_chanel();
	image[BLUE]=init_chanel();
	return image;
}

unsigned char **init_chanel()
{
	unsigned char **chanel;
	chanel = (unsigned char **) malloc(sizeof(unsigned char*)*480);
	for (int i=0 ; i < 480; i++)
	{
		chanel[i]=(unsigned char *) malloc(sizeof(unsigned char) * 640);
	}
	return chanel;
}

int **init_space(int height, int width)
{
	int **map;
	map = (int **) malloc(sizeof(int*)*height);
	for (int i=0 ; i < height; i++)
	{
		map[i]=(int *) malloc(sizeof(int) * width);
	}
	return map;
}

static void readBmp(char *filename, IMAGE image)
{
	FILE *fd;
	fd = fopen(filename, "rb");
	unsigned char header[54];
	fread(header, sizeof(unsigned char), 54, fd);
	unsigned char* data = (unsigned char *)malloc(640 * 3 * sizeof (unsigned int));
	for (int y = 0; y<480; y++)
	{
		fread(data, sizeof(unsigned char), 640 * 3, fd);
		for (int x = 0; x < 640 ;x ++)
		{
			int index=x*3;
			image[BLUE][y][x]= data[index + 0];
			image[GREEN][y][x]= data[index + 1];
			image[RED][y][x]= data[index + 2];
		}
	}
	free(data);
	fclose(fd);
}