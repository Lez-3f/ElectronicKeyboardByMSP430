/*
 * Music.h
 *
 *  Created on: 2021年8月27日
 *      Author: ZEL
 */

#ifndef MUSIC_H_
#define MUSIC_H_

//设置播放音乐时的灯光引脚
#define L3_pin BIT2
#define L5_pin BIT4
#define L6_pin BIT5


//青花瓷
const unsigned int QHC[92] = {
                            non, sol_m, sol_m, mi_m,
                            re_m, mi_m, la_l,
                            re_m, mi_m, sol_m, mi_m,
                            re_m,
                            non, sol_m, sol_m, mi_m,
                            re_m, mi_m, sol_l,
                            re_m, mi_m, sol_m, re_m,
                            do_m,
                            non, do_m, re_m, mi_m,
                            sol_m, la_m, sol_m, fa_m,
                            sol_m, mi_m, mi_m, re_m,
                            re_m,
                            non, do_m, re_m, do_m,
                            do_m, re_m, do_m, re_m,
                            re_m, mi_m, sol_m,
                            mi_m, mi_m,
                            //
                            non, sol_m, sol_m, mi_m,
                            re_m, mi_m, la_l,
                            re_m, mi_m, sol_m, mi_m,
                            re_m,
                            non, sol_m, sol_m, mi_m,
                            re_m, mi_m, sol_l,
                            re_m, mi_m, sol_m, re_m,
                            do_m,
                            non, do_m, re_m, mi_m,
                            sol_m, la_m, sol_m, fa_m,
                            sol_m, mi_m, mi_m, re_m,
                            re_m, sol_l,
                            mi_m, re_m, re_m,
                            do_m
};

const unsigned int Beats_QHC[92] = {
                                  b1, b1, b1, b1,
                                  b1, b1, b2,
                                  b1, b1, b1, b1,
                                  b4,
                                  b1, b1, b1, b1,
                                  b1, b1, b2,
                                  b1, b1, b1, b1,
                                  b4,
                                  b1, b1, b1, b1,
                                  b1, b1, b1, b1,
                                  b1, b1, b1, b1,
                                  b4,
                                  b1, b1, b1, b1,
                                  b1, b1, b1, b1,
                                  b1, b2, b1,
                                  b4,
                                  //
                                  b1, b1, b1, b1,
                                  b1, b1, b2,
                                  b1, b1, b1, b1,
                                  b4,
                                  b1, b1, b1, b1,
                                  b1, b1, b2,
                                  b1, b1, b1, b1,
                                  b4,
                                  b1, b1, b1, b1,
                                  b1, b1, b1, b1,
                                  b1, b1, b1, b1,
                                  b3, b1,
                                  b2, b1, b1,
                                  b4
};

const int note_num_QHC = 92;

//菊花台
const unsigned int JHT[24] = {
                            do_m, re_m,
                            mi_m,
                            mi_m, sol_m,
                            la_m,
                            la_m, mi_h,
                            re_h, do_h,
                            do_h, la_m,
                            sol_m,
                            la_m, sol_m,
                            mi_m, re_m,
                            do_m,
                            la_l, do_m,
                            re_m,
                            re_m, do_m,
                            re_m
};
const unsigned int Beats_JHT[24] = {
                                    b2, b2,
                                    b4,
                                    b2, b2,
                                    b4,
                                    b2, b2,
                                    b2, b2,
                                    b2, b2,
                                    b4,
                                    b2, b2,
                                    b2, b2,
                                    b4,
                                    b2, b2,
                                    b4,
                                    b2, b2,
                                    b4,
};
const unsigned int note_num_JHT = 24;

//闪亮的日子
const unsigned int SLDRZ[32] = {
                              mi_m, mi_l, mi_l,
                              mi_m, re_m, do_m, re_m, jmp,
                              mi_m, la_m,
                              mi_m, re_m, do_m, re_m, jmp,
                              mi_m, non, do_m, do_m,
                              re_m, re_m, mi_m,
                              la_l, non, la_l,
                              la_l, do_m, si_l, la_l, jmp,
                              la_l, non
};
const unsigned int Beats_SLDRZ[32] = {
                                      b8_3, b2_3, b2_3,
                                      b2, b2_3, b1_3, b1_3, b2_3,
                                      b8_3, b4_3,
                                      b2, b2_3, b1_3, b1_3, b2_3,
                                      b8_3, b2_3, b1_3, b1_3,
                                      b4_3, b2, b2_3,
                                      b8_3, b2_3, b2_3,
                                      b2, b2_3, b1_3, b1_3, b2_3,
                                      b8_3, b4_3
};
const unsigned int note_num_SLDRZ = 31;

#endif /* MUSIC_H_ */
