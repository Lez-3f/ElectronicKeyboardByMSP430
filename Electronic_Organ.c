/*
 * Electronic_Organ.c
 *
 *  Created on: 2021年8月27日
 *      Author: ZEL
 */
#include "msp430.h"
#include "Tone.h"
#include "Music.h"
#define MOD_1 1 //放歌模式
#define MOD_2 2 //弹奏模式
unsigned int mode;

//音速
#define LOW_SPEED 0x2000
#define SPEED 0x1000
#define HIGH_SPEED 0x800
unsigned int play_speed = SPEED;

//音量
#define VOLUME 10
#define HIGH_VOLUME 50
unsigned int volume = VOLUME;

/*
 * Key_Law
 * 1.0 k1 mi
 * 1.1 k2 si
 * 1.2--key_blue --up
 * 1.3 k4 la
 * 1.4 k5 re
 * 1.5 k6 sol
 * 1.6 k7 do
 * 1.7 k8 fa
 * 2.0 key_red --low
 * 2.1 buzz
 */
//蜂鸣器控制函数，传入指定的CCR0，产生特定的音调
void delay();

void buzz(unsigned int TA1CCR0_set, unsigned int beat)
{
    if(TA1CCR0_set != jmp)
    {
        TA1CCR0=TA1CCR0_set;
        TA1CCR1=TA1CCR0_set / volume;
        delay(beat);
        TA1CCR0 = 0;
    }
}

//延时函数
void delay(unsigned int beat)
{
    unsigned int i;
    for(i = 0;i < beat; i++)
    {
        unsigned int j;
        for(j = 0; j < play_speed; j++);
    }
}

//歌曲四拍间的暂停
void pause()
{
    unsigned int j;
    for(j = 0; j < play_speed;j++);
}

//歌曲生成函数
void Song_generate(const unsigned int *Song, const unsigned int *Beats, const unsigned int note_num, unsigned int Led_pin)
{
    unsigned int i;
    unsigned int beats_played = 0;
    //原速播放
    play_speed = SPEED;
    volume = VOLUME;
    for(i = 0;i < note_num; i++)
    {
        P2OUT ^= Led_pin; //灯光取反
        buzz(Song[i], Beats[i]);
        beats_played += Beats[i];
        if(beats_played == b4)
        {
            beats_played = 0;
            pause();
        }
        if((P1IN & BIT7) == 0) //按下K8，停止播放
        {
            P2OUT |= Led_pin;
            return;
        }
    }
    P2OUT |= Led_pin;
}

//歌曲播放模式
void Songs_singing_MODE()
{
    P2OUT &= ~BIT3;
    if((P1IN & BIT2) != 0 && (P2IN & BIT0) != 0) //按下蓝键，切换至弹奏模式
    {
        mode = MOD_2; //模式切换
    }
    else if((P1IN & BIT4) == 0) //K5按下，播放青花瓷，L3亮
    {
        Song_generate(QHC, Beats_QHC, note_num_QHC, L3_pin);
    }
    else if((P1IN & BIT5) == 0) //K6按下，播放菊花台， L5亮
    {
        Song_generate(JHT, Beats_JHT, note_num_JHT, L5_pin);
    }
    else if((P1IN & BIT6) == 0) //K7按下， 播放闪亮的日子， L6亮
    {
        Song_generate(SLDRZ, Beats_SLDRZ, note_num_SLDRZ, L6_pin);
    }
}

//弹奏模式
void Play_song_MODE( )
{
    if((P1IN & BIT2) != 0 && (P2IN & BIT0) != 0) //按下红键，切换至播放模式
    {
        mode = MOD_1; //模式切换
    }
    if((P1IN & BIT0) == 0) //1.0 --mi
    {
        while((P1IN & BIT0) == 0)
        {
            P2OUT ^= BIT5;
            if((P1IN & BIT2) != 0) buzz(mi_h, b1_2);
            else if((P2IN & BIT0) != 0) buzz(mi_l, b1_2);
            else buzz(mi_m, b1_2);
            P2OUT ^= BIT5;
        }
    }
    else if((P1IN & BIT1) == 0)
    {
        while((P1IN & BIT1) == 0)
        {
            P2OUT ^= BIT2;
            P2OUT ^= BIT4;
            P2OUT ^= BIT5;
            if((P1IN & BIT2) != 0) buzz(si_h, b1_2);
            else if((P2IN & BIT0) != 0) buzz(si_l, b1_2);
            else buzz(si_m, b1_2);
            P2OUT ^= BIT2;
            P2OUT ^= BIT4;
            P2OUT ^= BIT5;
        }
    }
    else if((P1IN & BIT3) == 0)
    {
        while((P1IN & BIT3) == 0)
        {
            P2OUT ^= BIT4;
            P2OUT ^= BIT5;
            if((P1IN & BIT2) != 0) buzz(la_h, b1_2);
            else if((P2IN & BIT0) != 0) buzz(la_l, b1_2);
            else buzz(la_m, b1_2);
            P2OUT ^= BIT4;
            P2OUT ^= BIT5;
        }
    }
    else if((P1IN & BIT4) == 0)
    {
        while((P1IN & BIT4) == 0)
        {
            P2OUT ^= BIT4;
            if((P1IN & BIT2) != 0) buzz(re_h, b1_2);
            else if((P2IN & BIT0) != 0) buzz(re_l, b1_2);
            else buzz(re_m, b1_2);
            P2OUT ^= BIT4;
        }
    }
    else if((P1IN & BIT5) == 0)
    {
        while((P1IN & BIT5) == 0)
        {
            P2OUT ^= BIT2;
            P2OUT ^= BIT5;
            if((P1IN & BIT2) != 0) buzz(sol_h, b1_2);
            else if((P2IN & BIT0) != 0) buzz(sol_l, b1_2);
            else buzz(sol_m, b1_2);
            P2OUT ^= BIT2;
            P2OUT ^= BIT5;
        }
    }
    else if((P1IN & BIT6) == 0)
    {
        while((P1IN & BIT6) == 0)
        {
            P2OUT ^= BIT2;
            if((P1IN & BIT2) != 0) buzz(do_h, b1_2);
            else if((P2IN & BIT0) != 0) buzz(do_l, b1_2);
            else buzz(do_m, b1_2);
            P2OUT ^= BIT2;
        }
    }
    else if((P1IN & BIT7) == 0)
    {
        while((P1IN & BIT7) == 0)
        {
            P2OUT ^= BIT2;
            P2OUT ^= BIT4;
            if((P1IN & BIT2) != 0) buzz(fa_h, b1_2);
            else if((P2IN & BIT0) != 0) buzz(fa_l, b1_2);
            else buzz(fa_m, b1_2);
            P2OUT ^= BIT2;
            P2OUT ^= BIT4;
        }
    }
}

int main()
{
    WDTCTL = WDTPW + WDTHOLD; //关闭看门狗
    P2SEL |=BIT1; //置 P2.1为定时器 TA1 的 PWM 输出引脚
    P2SEL2 &=~(BIT1); //P2.1 为比较器 1 的 PWM 输出引脚
    P2DIR |= BIT1;
    TA1CTL |=TASSEL0; //选择 TA1 计数时钟为 ACLK，使用上电复位设置，即 32768Hz
    TA1CCTL1|=OUTMOD1;
    TA1CTL |=TACLR+MC0; //设置增计数方式，使计数器从 0 开始计数，计数到 TA1CCR0 后又从 0 计数。

    //LED引脚设置， p2.2,  2.4, 2.5输出 //
    P2SEL &= ~(BIT2 + BIT4 + BIT5);
    P2SEL2 &= ~(BIT2 +BIT4 + BIT5);
    P2DIR |= (BIT2 + BIT4 + BIT5);
    P2OUT |= (BIT2 + BIT4 + BIT5);

    //开关引脚设置，p1全为输入 p2.0输入
    P1SEL = 0x00;
    P1SEL2 = 0x00;
    P1DIR = 0x00;
    P1REN = 0xff;
    P1OUT = 0xfb;

    P2SEL &= ~BIT0;
    P2SEL2 &= ~BIT0;
    P2DIR &= ~BIT0;
    P2REN |= BIT0;
    P2OUT &= ~BIT0;

    //中断引脚设置1.0, 1.1, 1.3,
    P1IES |= (BIT0 + BIT1 + BIT3);
    P1IFG &=~(BIT0 + BIT1 + BIT3);
    P1IE |= (BIT0 + BIT1 + BIT3);

    TA1CCR0 = 0;

    mode = MOD_1;
    _EINT();
    while(1){
        if(mode == MOD_1)
        {
            Songs_singing_MODE();
        }
        else if(mode == MOD_2)
        {
            Play_song_MODE();
        }
    };
}


//中断
#pragma vector=PORT1_VECTOR
__interrupt void port_ISR( )
{
    if(mode == MOD_1)//模式1
    {
        if((P1IN & BIT0) == 0) //k1 --暂停
        {
            unsigned int temp = TA1CCR0;
            TA1CCR0 = 0;
            while((P1IN & BIT0) != 0);
            TA1CCR0 = temp;
        }
        else if((P1IN & BIT1) == 0) //k2 快速模式
        {
            play_speed = HIGH_SPEED;
        }
        else if((P1IN & BIT3) == 0) //k4 慢速模式
        {
            play_speed = LOW_SPEED;

        }
    }
    P1IFG &=~(BIT0 + BIT1 + BIT3);
}

