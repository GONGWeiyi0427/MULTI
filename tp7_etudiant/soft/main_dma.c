
#include "stdio.h"

#define NPIXEL 256
#define NLINE  256

///////////////////////////////////////////////////////////////////////////////
//	main function
///////////////////////////////////////////////////////////////////////////////
__attribute__ ((constructor)) void main() 
{
    unsigned char 	BUF0[NPIXEL*NLINE];
    unsigned char 	BUF1[NPIXEL*NLINE];
    unsigned int 	line;
    unsigned int 	pixel;
    unsigned int 	step;

    for(step = 1 ; step < 7 ; step++)
    {
        int i = step - 1;
        tty_printf("\n*** damier %d ***\n\n",step);

        if(step % 2 == 0 && i > 0)  
        {
            for(pixel = 0 ; pixel < NPIXEL ; pixel++)
            { 
                for(line = 0 ; line < NLINE ; line++) 
                {
                    if( ( (pixel>>step & 0x1) && !(line>>step & 0x1)) || 
                        (!(pixel>>step & 0x1) &&  (line>>step & 0x1)) )  	BUF0[NPIXEL*line + pixel] = 0xFF;
                    else 							BUF0[NPIXEL*line + pixel] = 0x0;
                }
            }
        }

        else if(step % 2 != 0 && i < 4)
        {
            for(pixel = 0 ; pixel < NPIXEL ; pixel++)
            { 
                for(line = 0 ; line < NLINE ; line++) 
                {
                    if( ( (pixel>>step & 0x1) && !(line>>step & 0x1)) || 
                        (!(pixel>>step & 0x1) &&  (line>>step & 0x1)) )  	BUF1[NPIXEL*line + pixel] = 0xFF;
                    else 							BUF1[NPIXEL*line + pixel] = 0x0;
                }
            }
        }

        // for(pixel = 0 ; pixel < NPIXEL ; pixel++)
        // { 
        //     for(line = 0 ; line < NLINE ; line++) 
        //     {
        //         if( ( (pixel>>step & 0x1) && !(line>>step & 0x1)) || 
        //             (!(pixel>>step & 0x1) &&  (line>>step & 0x1)) )  	BUF[NPIXEL*line + pixel] = 0xFF;
        //         else 							BUF[NPIXEL*line + pixel] = 0x0;
        //     }
        // }

        tty_printf(" - build   OK at cycle %d\n", proctime());

    //     if(fb_sync_write(0, BUF, NLINE*NPIXEL) != 0)
	// {
    //         tty_printf("\n!!! error in fb_syn_write syscall !!!\n"); 
	//     exit();
	// }

        if (step % 2 == 0 && i > 0){
            if(fb_write(0, BUF0, NLINE*NPIXEL) != 0)
            {
                tty_printf("\n!!! error in fb_syn_write syscall !!!\n"); 
	            exit();
            }
        }

        else if (i < 4 && step %2 != 0)
        {
            if(fb_write(0, BUF1, NLINE*NPIXEL) != 0)
            {
                tty_printf("\n!!! error in fb_syn_write syscall !!!\n"); 
	            exit();
            }
        }
        

        if(step > 1 && step < 6) fb_completed();

        tty_printf(" - display OK at cycle %d\n", proctime());

    }
    tty_printf("\nFin du programme au cycle = %d\n\n", proctime());
    exit(); 
} // end main
