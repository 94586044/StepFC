﻿#pragma once
// License: MIT  http://opensource.org/licenses/MIT
// Author: dustpg   mailto:dustpg@gmail.com

#include <stdint.h>


/// <summary>
/// 
/// </summary>
enum sfc_channel_index {
    // [Sunsoft 5B] FME7
    SFC_FME7_Sun5B = -5,
    // [N163] N163
    SFC_VRC7_N163 = -4,
    // [VRC7] VRC7
    SFC_VRC7_VRC7 = -3,
    // [VRC6] VRC6
    SFC_VRC6_VRC6 = -2,
    // 帧计数器/序列器/[MMC5] 伪帧序列器
    SFC_FrameCounter = -1,
    // 总体
    SFC_Overview = 0,
    // [2A03] 方波#1
    SFC_2A03_Square1,
    // [2A03] 方波#2
    SFC_2A03_Square2,
    // [2A03] 三角波
    SFC_2A03_Triangle,
    // [2A03] 噪声
    SFC_2A03_Noise,
    // [2A03] DMC
    SFC_2A03_DMC,
    // [VRC6] 方波#1
    SFC_VRC6_Square1,
    // [VRC6] 方波#2
    SFC_VRC6_Square2,
    // [VRC6] 锯齿波
    SFC_VRC6_Saw,
    // [VRC7] FM声道#0
    SFC_VRC7_FM0,
    // [VRC7] FM声道#1
    SFC_VRC7_FM1,
    // [VRC7] FM声道#2
    SFC_VRC7_FM2,
    // [VRC7] FM声道#3
    SFC_VRC7_FM3,
    // [VRC7] FM声道#4
    SFC_VRC7_FM4,
    // [VRC7] FM声道#5
    SFC_VRC7_FM5,
    // [FDS1] 波形声道
    SFC_FDS1_Wavefrom,
    // [MMC5] 方波#1
    SFC_MMC5_Square1,
    // [MMC5] 方波#2
    SFC_MMC5_Square2,
    // [MMC5] PCM声道
    SFC_MMC5_PCM,
    // [N163] 波形#0
    SFC_N163_Wavefrom0,
    // [N163] 波形#1
    SFC_N163_Wavefrom1,
    // [N163] 波形#2
    SFC_N163_Wavefrom2,
    // [N163] 波形#3
    SFC_N163_Wavefrom3,
    // [N163] 波形#4
    SFC_N163_Wavefrom4,
    // [N163] 波形#5
    SFC_N163_Wavefrom5,
    // [N163] 波形#6
    SFC_N163_Wavefrom6,
    // [N163] 波形#7
    SFC_N163_Wavefrom7,
    // [FME7] 声道A
    SFC_FME7_ChannelA,
    // [FME7] 声道B
    SFC_FME7_ChannelB,
    // [FME7] 声道C
    SFC_FME7_ChannelC,
    // 总声道数量
    SFC_CHANNEL_COUNT
} ;

/// <summary>
/// 
/// </summary>
enum sfc_4015_write_flag {
    SFC_APU4015_WRITE_EnableSquare1 = 0x01, // 方波1 使能
    SFC_APU4015_WRITE_EnableSquare2 = 0x02, // 方波2 使能
    SFC_APU4015_WRITE_EnableTriangle= 0x04, // 三角波 使能
    SFC_APU4015_WRITE_EnableNoise   = 0x08, // 噪声 使能
    SFC_APU4015_WRITE_EnableDMC     = 0x10, // DMC 使能
};

/// <summary>
/// 
/// </summary>
enum sfc_4015_read_flag {
    SFC_APU4015_READ_Square1Length  = 0x01, // 方波1 长度计数器>0
    SFC_APU4015_READ_Square2Length  = 0x02, // 方波2 长度计数器>0
    SFC_APU4015_READ_TriangleLength = 0x04, // 三角波 长度计数器>0
    SFC_APU4015_READ_NoiseLength    = 0x08, // 三角波 长度计数器>0
    SFC_APU4015_READ_DMCActive      = 0x10, // DMC激活状态

    SFC_APU4015_READ_Frameinterrupt = 0x40, // 帧中断
    SFC_APU4015_READ_DMCInterrupt   = 0x80, // DMC中断
};

/// <summary>
/// 
/// </summary>
enum sfc_4017_flag {
    SFC_APU4017_ModeStep5   = 0x80, // 5步模式
    SFC_APU4017_IRQDisable  = 0x40, // IRQ禁用
};


/// <summary>
/// 
/// </summary>
enum sfc_apu_ctrl6_flag {
    SFC_APUCTRL6_ConstVolume= 0x10,    // 固定音量
    SFC_APUCTRL6_EnvLoop    = 0x20,    // 循环包络
};

/// <summary>
/// 包络
/// </summary>
typedef struct {
    // 时钟分频器
    uint8_t     divider;
    // 计数器
    uint8_t     counter;
    // 开始标记
    uint8_t     start;
    // 控制器低6位
    uint8_t     ctrl6;

} sfc_envelope_t;


/// <summary>
/// 方波寄存器/数据
/// </summary>
typedef struct {
    // 包络
    sfc_envelope_t  envelope;
    // 当前周期
    uint16_t        cur_period;
    // 序列索引
    uint8_t         seq_index;
    // 未使用/MMC5 用于$5015
    uint8_t         unused__mmc5_5015;
    // 长度计数器
    uint8_t         length_counter;
    // 控制寄存器
    uint8_t         ctrl;
    // 扫描单元: 重载
    uint8_t         sweep_reload;
    // 扫描单元: 使能
    uint8_t         sweep_enable;
    // 扫描单元: 反相扫描
    uint8_t         sweep_negate;
    // 扫描单元: 时钟分频器周期
    uint8_t         sweep_period;
    // 扫描单元: 时钟分频器
    uint8_t         sweep_divider;
    // 扫描单元: 移位器
    uint8_t         sweep_shift;

} sfc_square_data_t;


/// <summary>
/// 三角波寄存器/数据
/// </summary>
typedef struct {
    // 当前周期
    uint16_t        cur_period;
    // 长度计数器
    uint8_t         length_counter;
    // 线性计数器
    uint8_t         linear_counter;
    // 线性计数器 重载值
    uint8_t         value_reload;
    // 线性计数器 重载标志
    uint8_t         flag_reload;
    // 长度计数器/线性计数器暂停值
    uint8_t         flag_halt;
} sfc_triangle_data_t;

/// <summary>
/// 
/// </summary>
typedef struct  {
    // 包络
    sfc_envelope_t  envelope;
    // 线性反馈移位寄存器(暂时没用到)
    uint16_t        lfsr;
    // 长度计数器
    uint8_t         length_counter;
    // 短模式[D7] 周期索引[D0-D3]
    uint8_t         short_mode__period_index;

} sfc_noise_data_t;

/// <summary>
/// 
/// </summary>
typedef struct {
    // 原始地址
    uint16_t        orgaddr;
    // 当前地址
    uint16_t        curaddr;
    // 原始长度
    uint16_t        length;
    // 剩余长度
    uint16_t        lenleft;
    // 周期
    uint16_t        period;
    // 周期索引
    uint16_t        index;
    // 输出
    uint8_t         value;
    // 中断[D1]/循环[D0]
    uint8_t         irq_loop;
    // 8步计数
    uint8_t         count;
    // 字节数据
    uint8_t         data;

} sfc_dmc_data_t;


/// <summary>
/// VRC6 方波数据
/// </summary>
typedef struct {
    // 周期
    uint16_t        period;
    // 周期-原始
    uint16_t        period_raw;
    // 音量
    uint8_t         volume;
    // 占空比
    uint8_t         duty;
    // 使能位
    uint8_t         enable;
    // 索引
    uint8_t         index;
} sfc_vrc6_square_data_t;

/// <summary>
/// VRC6 锯齿波数据
/// </summary>
typedef struct {
    // 周期
    uint16_t        period;
    // 周期-原始
    uint16_t        period_raw;
    // 累加率
    uint8_t         rate;
    // 内部累加器
    uint8_t         accumulator;
    // 使能位
    uint8_t         enable;
    // 增加次数
    uint8_t         count;
} sfc_vrc6_saw_data_t;

/// <summary>
/// VRC6数据
/// </summary>
typedef struct {
    // 方波 #1
    sfc_vrc6_square_data_t      square1;
    // 方波 #2
    sfc_vrc6_square_data_t      square2;
    // 锯齿波
    sfc_vrc6_saw_data_t         saw;
    // 频率控制
    uint8_t                     freq_ctrl;
    // 暂停
    uint8_t                     halt;
} sfc_vrc6_data_t;



// 可修改
enum {
#if 1
    // VRC7 半正弦表位长
    SFC_VRC7_HALF_SINE_LUT_BIT = 10,
    // VRC7 AM 表位长
    SFC_VRC7_AM_LUT_BIT = 8,
    // VRC7 FM 表位长
    SFC_VRC7_FM_LUT_BIT = 8,
    // VRC7 Attack输出 表位长
    SFC_VRC7_ATKOUT_LUT_BIT = 8,
    // VRC7 衰减转线性查找表位长
    SFC_VRC7_A2L_LUT_BIT = 15,
#else
    // VRC7 半正弦表位长
    SFC_VRC7_HALF_SINE_LUT_BIT = 16,
    // VRC7 AM 表位长
    SFC_VRC7_AM_LUT_BIT = 16,
    // VRC7 FM 表位长
    SFC_VRC7_FM_LUT_BIT = 16,
    // VRC7 Attack输出 表位长
    SFC_VRC7_ATKOUT_LUT_BIT = 16,
    // VRC7 衰减转线性查找表位长
    SFC_VRC7_A2L_LUT_BIT = 16,
#endif
};


/// <summary>
/// VRC7 FM算子
/// </summary>
typedef struct {
    // 前一输出
    int32_t     prev_output;
    // 前一最终输出
    int32_t     prev_final;
    // [18bit] 相位
    uint32_t    phase;
    // [23bit] 包络发生器计数器
    uint32_t    egc;
    // Base 值
    uint32_t    base;
    // Key Scale 值
    uint32_t    key_scale;
    // 相位 速率 4倍以保证精度
    uint32_t    phase_rate_x4;
    // 包络状态 IADSR
    uint32_t    state;
    // Attack 速率
    uint32_t    attack_rate;
    // Decay 速率
    uint32_t    decay_rate;
    // Sustain 速率
    uint32_t    sustain_rate;
    // Release 速率
    uint32_t    release_rate;
    // Sustain 值
    uint32_t    sustain_level;

} sfc_vrc7_operator_t;

/// <summary>
/// VRC7 声道数据
/// </summary>
typedef struct {
    // 调制
    sfc_vrc7_operator_t modulator;
    // 载波
    sfc_vrc7_operator_t carrier;
    // 频率 [9bit]
    uint16_t    freq;
    // 八度 [3bit]
    uint8_t     octave;
    // 开关 [1bit]
    uint8_t     trigger;
    // 延音 [1bit]
    uint8_t     sustain;
    // 乐器 [4bit] 已经预乘8 [0XXX X000]
    uint8_t     instrument8;
    // 音量 [4bit]
    uint8_t     volume;
    // 控制信息 $2X 低四位
    uint8_t     low4bit;
} sfc_vrc7_ch_t;


#ifdef SFC_FM_FLOAT
typedef float sfc_vrc7_fm_t;
#else
typedef int32_t sfc_vrc7_fm_t;
#endif

/// <summary>
/// VRC7数据
/// </summary>
typedef struct {
    // 6个声道
    sfc_vrc7_ch_t   ch[6];
    // [20bit] AM相位
    uint32_t        am_phase;
    // [20bit] FM相位
    uint32_t        fm_phase;
    // AM 输出
    uint32_t        am_output;
    // FM 输出
    sfc_vrc7_fm_t   fm_output;
    // 寄存器选择
    uint8_t         selected;
    // 未使用
    uint8_t         unused[3];
} sfc_vrc7_data_t;



/// <summary>
/// FDS 数据
/// </summary>
typedef struct {
    // 音量包络当前时钟
    uint32_t        volenv_clock;
    // 调制包络当前时钟
    uint32_t        modenv_clock;
    // 波形输出用时钟
    uint32_t        wavout_clock;
    // 调制单元用时钟
    uint32_t        mdunit_clock;
    // 音量包络增长 TickPerClock
    uint32_t        volenv_tpc;
    // 调制包络增长 TickPerClock
    uint32_t        modenv_tpc;
    // [12bit] 基础频率     $4082-$4083
    uint16_t        freq;
    // [12bit] 基础频率-增益
    int16_t         freq_gain;
    // [12bit] 基础频率-已增益
    uint16_t        freq_gained;
    // [12bit] 调制频率     $4085-$4086
    uint16_t        mod_freq;
    // [8 bit] 音量包络     $4083 
    uint8_t         volenv_4080;
    // [2 bit] $4083 高2bit 相关标志位
    uint8_t         flags_4083;
    // [6 bit] 音量增益     $4080
    uint8_t         volenv_gain;
    // [5 bit] 音量增益钳制
    uint8_t         volenv_gain_clamped;
    // [8 bit] 调制包络     $4084
    uint8_t         modenv_4084;
    // [6 bit] 调制增益     $4084
    uint8_t         modenv_gain;
    // [7 bit] 调制计数(由于有符号利用高7bit实现)
    int8_t          mod_counter_x2;
    // [8 bit] 主包络速率 [默认0xE8]
    uint8_t         masenv_speed;
    // 调制使能
    uint8_t         mod_enabled;
    // 调制表位
    uint8_t         modtbl_index;
    // 允许写入
    uint8_t         write_enable;
    // 主音量  (除以30)
    uint8_t         master_volume;
    // 波索引位置
    uint8_t         wavtbl_index;
    // 波输出数据
    uint8_t         waveout;

} sfc_fds1_data_t;

enum {
    SFC_FDS_4080_GainMode       = 0x80,
    SFC_FDS_4080_Increase       = 0x40,

    SFC_FDS_4083_DisableEnv     = 0x40,
    SFC_FDS_4083_HaltWave       = 0x80,

    SFC_FDS_4084_GainMode       = 0x80,
    SFC_FDS_4084_Increase       = 0x40,

    SFC_FDS_MASTER_VOL_LCM = 30
};



/// <summary>
/// 
/// </summary>
typedef struct {
    // 方波 #1
    sfc_square_data_t       square1;
    // 方波 #2
    sfc_square_data_t       square2;
    // 方波 #1 时钟
    uint16_t                square1_clock;
    // 方波 #2 时钟
    uint16_t                square2_clock;
    // PCM 输出
    uint8_t                 pcm_output;
    // PCM IRQ 使能
    uint8_t                 pcm_irq_enable;
    // PCM IRQ 触发
    uint8_t                 pcm_irq_tri;
    // PCM 写入掩码
    uint8_t                 pcm_mask;
} sfc_mmc5_data_t;



/// <summary>
/// 
/// </summary>
typedef struct {
    // N163 周期计数器(0~15)
    uint8_t     n163_clock;
    // N163 当前声道
    uint8_t     n163_current;
    // N163 声道数量
    uint8_t     n163_count;
    // N163 声道最低编号
    uint8_t     n163_lowest_id;
    // 副权重(除以16)
    uint8_t     subweight_div16;
    // 写入地址
    uint8_t     n163_addr;
    // 地址递增
    uint8_t     n163_inc;
    // 历史输出位置
    uint16_t    history_index;
    // 当前输出
    int8_t      ch_output[8];
    // 历史输出
    int8_t      history_output[8];
} sfc_n163_data_t;


/// <summary>
/// Sunsoft 5B 声道
/// </summary>
typedef struct {
    // 时钟
    uint16_t        clock;
    // 周期
    uint16_t        period;
    // 音量
    uint16_t        volume;
    // 噪声
    uint8_t         tone;
    // 噪声
    uint8_t         noise;
    // 禁用
    uint8_t         disable;
    // 包络
    uint8_t         env;
    // 方波值
    uint8_t         square;
    // 不同声道使用不同
    union {
        // [0]    寄存器选择
        uint8_t     a0_reg_select;
    }               ;
} sfc_sunsoft5b_ch_t;

typedef struct {
    // 线性反馈移位寄存器
    uint32_t            lfsr;
    // 声道
    sfc_sunsoft5b_ch_t  ch[3];
    // 包络时钟
    uint16_t            env_clock;
    // 包络周期
    uint16_t            env_period;
    // 包络音量
    uint16_t            env_volume;
    // 噪声时钟
    uint16_t            noise_clock;
    // 噪声周期
    uint8_t             noise_period;
    // 包络形状
    uint8_t             evn_shape;
    // 包络索引
    uint8_t             evn_index;
    // 包络重复
    uint8_t             evn_repeat;
} sfc_fme7_data_t;

/// <summary>
/// APU寄存器数据
/// </summary>
typedef struct {
    // 方波 #1
    sfc_square_data_t       square1;
    // 方波 #2
    sfc_square_data_t       square2;
    // 三角波
    sfc_triangle_data_t     triangle;
    // 噪声
    sfc_noise_data_t        noise;
    // DMC
    sfc_dmc_data_t          dmc;
    // VRC6
    sfc_vrc6_data_t         vrc6;
    // VRC7
    sfc_vrc7_data_t         vrc7;
    // FDS1
    sfc_fds1_data_t         fds;
    // MMC5
    sfc_mmc5_data_t         mmc5;
    // N163
    sfc_n163_data_t         n163;
    // FME7
    sfc_fme7_data_t         fme7;
    // 状态寄存器(写: 声道使能)
    uint8_t                 status_write;
    // 状态寄存器(读:)
    //uint8_t                 status_read;
    // 帧计数器(序列器)写入寄存器
    uint8_t                 frame_counter;
    // 帧中断标志
    uint8_t                 frame_interrupt;
    // 步数计数
    uint8_t                 frame_step;

} sfc_apu_register_t;


// typedef
struct sfc_famicom;
typedef struct sfc_famicom sfc_famicom_t;

// 重置后
void sfc_apu_on_reset(sfc_apu_register_t*);

// 触发一次帧计数器
void sfc_trigger_frame_counter(sfc_famicom_t*);


// LFSR 长模式
static inline uint16_t sfc_lfsr_long(uint16_t v) {
    const uint16_t bit = ((v >> 0) ^ (v >> 1)) & 1;
    return (uint16_t)(v >> 1) | (uint16_t)(bit << 14);
}

// LFSR 短模式
static inline uint16_t sfc_lfsr_short(uint16_t v) {
    const uint16_t bit = ((v >> 0) ^ (v >> 6)) & 1;
    return (uint16_t)(v >> 1) | (uint16_t)(bit << 14);
}


// LFSR FME7模式 - Galois LFSR
static inline uint32_t sfc_lfsr_fme7(uint32_t v) {
    // D16 D13
    const uint32_t bit = v & 1; v >>= 1;
    // 实现1
    //if (bit) v ^= (uint32_t)0x12000;
    // 实现2
    const uint32_t mask = (uint32_t)(-(int32_t)bit);
    v ^= mask & (uint32_t)0x12000;
    return v;
}
