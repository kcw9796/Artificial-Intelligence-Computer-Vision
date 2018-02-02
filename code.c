#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void detect_line (unsigned char ***image, float *m, float *b)
{
	// PUT YOUR CODE HERE
	// access the image using "image[chanel][y][x]"
	// set m and b using the * operator
	// to create a bidimentional structure you can use "int **space=init_space(heigh, width);"

	int y,x,m_index,b_index,vote_max;
	int **votes=init_space(13280, 2001);
	float m_val,b_val;
	

	
	for(b_index=0;b_index<13280;b_index++)
	{
		for(m_index=0;m_index<=2000;m_index++)
		{
			votes[b_index][m_index]=0;
		}	
	}

	for(y=0;y<HEIGHT;y++)
	{
		for(x=0;x<WIDTH;x++)
		{
			if(image[RED][y][x]==0 && image[GREEN][y][x]==0 && image[BLUE][y][x]==0)
			{
				for(m_index=0;m_index<=2000;m_index++)
				{
					m_val = (float)(m_index)*0.01-10;
					b_val = y-m_val*x;
					b_index = b_val+6400;
					if(b_val>=-6390 && b_val<=6869)
					{
						votes[b_index][m_index]++;
					}
				}
			}
		}
	}

	vote_max = 0;
	
	for(b_index=0;b_index<13280;b_index++)
	{
		for(m_index=0;m_index<=2000;m_index++)
		{
			if(votes[b_index][m_index]>vote_max)
			{
				*m = (float)(m_index)*0.01-10;
				*b = b_index-6400;
				vote_max = votes[b_index][m_index];
			}
		}	
	}

	*m *= -1;
	*b = 480-(*b);

}

bool edge_check (unsigned char ***image, int x, int y)
{
	if(image[RED][y][x]<255 || image[GREEN][y][x]<255 || image[BLUE][y][x]<255)
	{
		if(x==0 || x==WIDTH-1 || y==0 || y==HEIGHT-1)
		{
			return true;
		}
		else
		{
			if((image[RED][y][x+1]==255 && image[GREEN][y][x+1]==255 && image[BLUE][y][x+1]==255) || (image[RED][y][x-1]==255 && image[GREEN][y][x-1]==255 && image[BLUE][y][x-1]==255) ||
					(image[RED][y+1][x]==255 && image[GREEN][y+1][x]==255 && image[BLUE][y+1][x]==255) || (image[RED][y-1][x]==255 && image[GREEN][y-1][x]==255 && image[BLUE][y-1][x]==255) ||
					(image[RED][y+1][x+1]==255 && image[GREEN][y+1][x+1]==255 && image[BLUE][y+1][x+1]==255) || (image[RED][y-1][x+1]==255 && image[GREEN][y-1][x+1]==255 && image[BLUE][y-1][x+1]==255) ||
					(image[RED][y+1][x-1]==255 && image[GREEN][y+1][x-1]==255 && image[BLUE][y+1][x-1]==255) || (image[RED][y-1][x-1]==255 && image[GREEN][y-1][x-1]==255 && image[BLUE][y-1][x-1]==255))
			{
				return true;
			}
			return false;
		}
	}
	return false;
}

int detect_polygon (unsigned char ***image)
{
	// PUT YOUR CODE HERE
	// access the image using "image[chanel][y][x]"
	// return the number of sides of the polygon
	// to create a bidimentional structure you can use "int **space=init_space(heigh, width);"

	int y,x,t_index,w_index,vote_max,vote_threshold=125,sides=0,count=0;
	int **votes=init_space(1601, 181);
	float t_val,w_val;
	

	for(w_index=0;w_index<=1600;w_index++)
	{
		for(t_index=0;t_index<=180;t_index++)
		{
			votes[w_index][t_index]=0;
		}
		
	}

	for(y=0;y<HEIGHT;y++)
	{
		for(x=0;x<WIDTH;x++)
		{
			if(edge_check(image, x, y))
			{
				count++;
				for(t_index=0;t_index<=179;t_index++)
				{
					t_val = (double)(t_index*M_PI/180);
					w_val = (float)(x*cos(t_val)-y*sin(t_val));
					w_index = (int)w_val+800;
					// if(t_index==110)
					// 	printf("%d %d %f\n", x,y,w_val);
					if(w_index>=0 && w_index<=1600)
					{
						votes[w_index][t_index]++;
					}
				}
			}
		}
	}
	
	// int **mergevotes=init_space(1601, 181);
	
	// for(w_index=0;w_index<=1600;w_index++)
	// {
	// 	for(t_index=0;t_index<=180;t_index++)
	// 	{
	// 		mergevotes[w_index][t_index] = votes[w_index][t_index];
	// 		if(t_index>0)
	// 		{
	// 			mergevotes[w_index][t_index] += votes[w_index][t_index-1];
	// 			if(w_index>0)
	// 				mergevotes[w_index][t_index] += votes[w_index-1][t_index-1];
	// 			if(w_index<1600)
	// 				mergevotes[w_index][t_index] += votes[w_index+1][t_index-1];
	// 		}	
	// 		if(t_index<180)
	// 		{
	// 			mergevotes[w_index][t_index] += votes[w_index][t_index+1];
	// 			if(w_index>0)
	// 				mergevotes[w_index][t_index] += votes[w_index-1][t_index+1];
	// 			if(w_index<1600)
	// 				mergevotes[w_index][t_index] += votes[w_index+1][t_index-1];
	// 		}
	// 		if(w_index>0)
	// 			mergevotes[w_index][t_index] += votes[w_index-1][t_index];
	// 		if(w_index<1600)
	// 			mergevotes[w_index][t_index] += votes[w_index+1][t_index];	
	// 	}
			
	// }

	// printf("%d\n", count);
	vote_max = 0;
	
	for(w_index=0;w_index<=1600;w_index++)
	{
		for(t_index=0;t_index<=180;t_index++)
		{
			if(votes[w_index][t_index]>vote_max)
			vote_max = votes[w_index][t_index];
		}
	}

	float prev_t=-10,prev_w=-10;
	
	for(w_index=0;w_index<=1600;w_index++)
	{
		for(t_index=0;t_index<=180;t_index++)
		{
			if(votes[w_index][t_index]>vote_max*0.7 || votes[w_index][t_index]>vote_threshold)
			// if(votes[w_index][t_index] > vote_threshold)
			{	
				if(t_index>=prev_t+2 || w_index>=prev_w+8)
				{
					sides++;
					// printf("%d %d %d\n", t_index, w_index, votes[w_index][t_index]);
					prev_t = t_index;
					prev_w = w_index;
				}	
				
			}
		}
	}


	return sides;
}


int circle_on_top (unsigned char ***image)
{
	// PUT YOUR CODE HERE
	// access the image using "image[chanel][y][x]"
	// return RED or BLUE
	// to create a bidimentional structure you can use "int **space=init_space(heigh, width);"

	int y,x,index,a_val,b_val,r_index,r_val,b_count=0,r_count=0;
	int **rvotes=init_space(307200, 176);
	int **bvotes=init_space(307200, 176);

	// int q = (int)sqrt((double)((154-250)*(154-250)+(235-143)*(235-143)));
	// printf("%d\n", q);

	for(index=0;index<307200;index++)
	{
		for(r_index=0;r_index<=175;r_index++)
		{
			rvotes[index][r_index]=0;
			bvotes[index][r_index]=0;
		}
	}

	for(y=0;y<HEIGHT;y++)
	{
		for(x=0;x<WIDTH;x++)
		{
			if(image[RED][y][x]==255 && image[GREEN][y][x]==0 && image[BLUE][y][x]==0)
				r_count++;
			if(image[RED][y][x]==0 && image[GREEN][y][x]==0 && image[BLUE][y][x]==255)
				b_count++;
			if(image[RED][y][x]==255 && image[GREEN][y][x]==0 && image[BLUE][y][x]==0 && edge_check(image,x,y))
			{
				for(index=0;index<307200;index++)
				{
					a_val = index%640;
					b_val = floor(index/640);
					r_val = (int)sqrt((double)((x-a_val)*(x-a_val)+(y-b_val)*(y-b_val)));
					r_index = r_val-25;
					if(r_index>=0 && r_index<=175)
					{
						rvotes[index][r_index]++;
					}
				}
			}
			if(image[RED][y][x]==0 && image[GREEN][y][x]==0 && image[BLUE][y][x]==255 && edge_check(image,x,y))
			{
				for(index=0;index<307200;index++)
				{
					a_val = index%640;
					b_val = floor(index/640);
					r_val = (int)sqrt((double)((x-a_val)*(x-a_val)+(y-b_val)*(y-b_val)));
					r_index = r_val-25;
					if(r_index>=0 && r_index<=175)
					{
						bvotes[index][r_index]++;
					}
				}
			}
		}
	}

	int vote_max_red = 0,vote_max_blue = 0;
	int r_fit_red = 25,r_fit_blue = 25;
	for(index=0;index<307200;index++)
	{
		for(r_index=0;r_index<=175;r_index++)
		{
			if(rvotes[index][r_index]>vote_max_red)
			{
				vote_max_red = rvotes[index][r_index];
				r_fit_red = r_index+25;
			}
			if(bvotes[index][r_index]>vote_max_blue)
			{
				vote_max_blue = bvotes[index][r_index];
				r_fit_blue = r_index+25;
			}
		}
	}

	// printf("%d\n", r_count);
	// printf("%d\n", r_fit_red);
	// printf("%d\n", b_count);
	// printf("%d\n", r_fit_blue);
	if(r_count/(M_PI*r_fit_red*r_fit_red)<b_count/(M_PI*r_fit_blue*r_fit_blue))
		return BLUE;

	return RED;
}






