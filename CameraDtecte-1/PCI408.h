#ifndef ___PCI408_LIB_H
#define ___PCI408_LIB_H

//这一段无需改动  //This segment should not be modified
#ifndef TRUE
#define TRUE  1
#endif

#ifndef FALSE
#define FALSE 0
#endif

/* Define NULL pointer value */

#ifndef NULL
#ifdef  __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif


typedef int                          BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef unsigned long		DWORD;
typedef float                       FLOAT;


#define __PCI408_EXPORTS

//定义输入和输出
#ifdef __PCI408_EXPORTS
	#define PCI408_API __declspec(dllexport)
#else
	#define PCI408_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

//---------------------   板卡初始和配置函数  ----------------------
/********************************************************************************
** 函数名称: PCI408_card_init
** 功能描述: 控制板初始化，设置初始化和速度等设置
** 输　  入: 无
** 返 回 值: 0：无卡； 1-8：成功(实际卡数)
**
*********************************************************************************/
PCI408_API int __stdcall PCI408_card_init(void);

/********************************************************************************
** 函数名称: PCI408_card_close
** 功能描述: 关闭所有卡
** 输　  入: 无
** 返 回 值: 无
** 日    期: 2007.02.1
*********************************************************************************/
PCI408_API void __stdcall PCI408_card_close(void);

/********************************************************************************
** 函数名称: 控制卡复位
** 功能描述: 复位所有卡，只能在初始化完成之后调用．
** 输　  入: 卡号
** 返 回 值: 错误码
** 日    期: 2007.02.1
*********************************************************************************/
PCI408_API DWORD __stdcall PCI408_card_reset(WORD card);

PCI408_API DWORD __stdcall PCI408_get_card_version(WORD card);
PCI408_API DWORD __stdcall PCI408_get_card_soft_version(WORD card, WORD* firm_id, DWORD* sub_firm_id);

PCI408_API DWORD __stdcall PCI408_get_client_ID(WORD card);

PCI408_API DWORD __stdcall PCI408_get_lib_version(void);
PCI408_API DWORD __stdcall PCI408_get_card_ID(WORD card);
PCI408_API DWORD __stdcall PCI408_get_total_axes(WORD card);
PCI408_API DWORD __stdcall PCI408_test_software(WORD card, WORD testid, WORD para1, WORD para2, WORD para3);
PCI408_API DWORD __stdcall PCI408_test_hardware(WORD card);
PCI408_API DWORD __stdcall PCI408_download_firmware(WORD card, const char* pfilename);


//脉冲输入输出配置
PCI408_API DWORD __stdcall PCI408_set_pulse_outmode(WORD axis,WORD outmode);
PCI408_API DWORD __stdcall PCI408_counter_config(WORD axis,WORD mode);

//添加配置读
PCI408_API DWORD __stdcall PCI408_get_pulse_outmode(WORD axis,WORD *outmode);
PCI408_API DWORD __stdcall PCI408_get_counter_config(WORD axis,WORD* mode);

PCI408_API DWORD __stdcall PCI408_get_config_SD_PIN(WORD axis,WORD *enable, WORD *sd_logic,WORD *sd_mode);

PCI408_API DWORD __stdcall PCI408_get_config_INP_PIN(WORD axis,WORD* enable,WORD* inp_logic);
PCI408_API DWORD __stdcall PCI408_get_config_ERC_PIN(WORD axis,WORD* enable,WORD* erc_logic,
				WORD* erc_width,WORD* erc_off_time);
PCI408_API DWORD __stdcall PCI408_get_config_ALM_PIN(WORD axis, WORD* enable, WORD* alm_logic,WORD* alm_action);
PCI408_API DWORD __stdcall PCI408_get_config_EL_PIN(WORD axis, WORD* el_logic, WORD* el_mode);

PCI408_API DWORD __stdcall PCI408_get_config_HOME_PIN_logic(WORD axis,WORD* org_logic,WORD* filter);
PCI408_API DWORD __stdcall PCI408_get_config_home_mode(WORD axis,WORD* home_dir, double* vel,WORD* home_mode,WORD* EZ_count);

PCI408_API DWORD __stdcall PCI408_get_handwheel_inmode(WORD axis, WORD * inmode, double* multi);

PCI408_API DWORD __stdcall PCI408_get_config_LTC_PIN(WORD axis,WORD* ltc_logic, WORD* ltc_mode);
PCI408_API DWORD __stdcall PCI408_get_config_latch_mode(WORD cardno, WORD* all_enable);


//专用信号设置函数
PCI408_API DWORD __stdcall PCI408_config_SD_PIN(WORD axis,WORD enable, WORD sd_logic,WORD sd_mode);

PCI408_API DWORD __stdcall PCI408_config_INP_PIN(WORD axis,WORD enable,WORD inp_logic);
PCI408_API DWORD __stdcall PCI408_config_ERC_PIN(WORD axis,WORD enable,WORD erc_logic,
				WORD erc_width,WORD erc_off_time);

PCI408_API DWORD __stdcall PCI408_config_EMG_PIN(WORD cardno, WORD option, WORD emg_logic);
PCI408_API DWORD __stdcall PCI408_get_config_EMG_PIN(WORD cardno, WORD* enbale, WORD* emg_logic);

PCI408_API DWORD __stdcall PCI408_config_ALM_PIN(WORD axis, WORD enable, WORD alm_logic,WORD alm_action);
//new
PCI408_API DWORD __stdcall PCI408_config_EL_PIN(WORD axis, WORD el_logic, WORD el_mode);

PCI408_API DWORD __stdcall PCI408_config_HOME_PIN_logic(WORD axis,WORD org_logic,WORD filter);

PCI408_API DWORD __stdcall PCI408_write_SEVON_PIN(WORD axis, WORD on_off);
PCI408_API int __stdcall PCI408_read_SEVON_PIN(WORD axis);

PCI408_API DWORD __stdcall PCI408_write_ERC_PIN(WORD axis, WORD sel);
PCI408_API int __stdcall PCI408_read_RDY_PIN(WORD axis);

PCI408_API DWORD __stdcall PCI408_set_backlash(WORD axis, long backlash);
PCI408_API DWORD __stdcall PCI408_get_backlash(WORD axis, long* backlash);

//通用输入/输出控制函数
PCI408_API int __stdcall PCI408_read_inbit(WORD cardno, WORD bitno);
PCI408_API DWORD __stdcall PCI408_write_outbit(WORD cardno, WORD bitno,WORD on_off);
PCI408_API int __stdcall  PCI408_read_outbit(WORD cardno, WORD bitno) ;
PCI408_API long __stdcall PCI408_read_inport(WORD cardno);
PCI408_API long __stdcall PCI408_read_outport(WORD cardno) ;
PCI408_API DWORD __stdcall PCI408_write_outport(WORD cardno, DWORD port_value);

//制动函数
PCI408_API DWORD __stdcall PCI408_decel_stop(WORD axis,double dec);
PCI408_API DWORD __stdcall PCI408_imd_stop(WORD axis);
PCI408_API DWORD __stdcall PCI408_emg_stop(void) ;
PCI408_API DWORD __stdcall PCI408_simultaneous_stop(WORD axis) ;

//位置设置和读取函数
PCI408_API long __stdcall PCI408_get_position(WORD axis);
PCI408_API DWORD __stdcall PCI408_set_position(WORD axis,long current_position);


//状态检测函数
PCI408_API int __stdcall  PCI408_check_done(WORD axis) ;
PCI408_API DWORD __stdcall PCI408_axis_io_status(WORD axis);


//速度设置
PCI408_API double __stdcall PCI408_read_current_speed(WORD axis);
PCI408_API double __stdcall PCI408_read_vector_speed(WORD card);
PCI408_API DWORD __stdcall PCI408_change_speed(WORD axis,double Curr_Vel);

PCI408_API DWORD __stdcall PCI408_set_vector_profile(WORD cardno,double s_para, double Max_Vel, double acc,double dec );
PCI408_API DWORD __stdcall PCI408_get_vector_profile(WORD cardno,double* s_para, double* Max_Vel, double* acc,double* dec );

PCI408_API DWORD __stdcall PCI408_set_profile(WORD axis,double option,double Max_Vel,double acc,double dec);
PCI408_API DWORD __stdcall PCI408_set_profile_ex(WORD axis,double Min_Vel,double Max_Vel,double stopspeed,double Tacc,double Tdec);
PCI408_API DWORD __stdcall PCI408_set_s_profile(WORD axis,double s_para);

PCI408_API DWORD __stdcall PCI408_get_profile(WORD axis,double* option,double* Max_Vel,double* acc,double* dec);
PCI408_API DWORD __stdcall PCI408_get_profile_ex(WORD axis,double* option,double* Max_Vel,double *stopspeed,double* acc,double* dec);
PCI408_API DWORD __stdcall PCI408_get_s_profile(WORD axis,double* s_para);

PCI408_API DWORD __stdcall PCI408_reset_target_position(WORD axis,long dist);

//单轴定长运动
PCI408_API DWORD __stdcall PCI408_pmove(WORD axis,long Dist,WORD posi_mode);

//单轴连续运动
PCI408_API DWORD __stdcall PCI408_vmove(WORD axis,WORD dir, double vel);

//线性插补
PCI408_API DWORD __stdcall PCI408_line2(WORD axis1,long Dist1,WORD axis2,long Dist2,WORD posi_mode);
PCI408_API DWORD __stdcall PCI408_line3(WORD *axis,long Dist1,long Dist2,long Dist3,WORD posi_mode);
PCI408_API DWORD __stdcall PCI408_line4(WORD cardno,long Dist1,long Dist2,long Dist3,long Dist4,WORD posi_mode);

//手轮运动
PCI408_API DWORD __stdcall PCI408_set_handwheel_inmode(WORD axis,WORD inmode, double multi);
PCI408_API DWORD __stdcall PCI408_handwheel_move(WORD axis);

//找原点
PCI408_API DWORD __stdcall PCI408_config_home_mode(WORD axis,WORD home_dir, double vel, WORD mode, WORD EZ_count);
PCI408_API DWORD __stdcall PCI408_home_move(WORD axis);

//圆弧插补
PCI408_API DWORD __stdcall PCI408_arc_move(WORD *axis,long *target_pos,long *cen_pos, WORD arc_dir);
PCI408_API DWORD __stdcall PCI408_rel_arc_move(WORD *axis,long *rel_pos,long *rel_cen, WORD arc_dir);

//设置和读取位置比较信号
PCI408_API DWORD __stdcall PCI408_compare_config(WORD card, WORD enable, WORD axis,  WORD cmp_source);
PCI408_API DWORD __stdcall PCI408_compare_get_config(WORD card, WORD* enable, WORD* axis,  WORD* cmp_source);

PCI408_API DWORD __stdcall PCI408_compare_clear_points(WORD card);
PCI408_API DWORD __stdcall PCI408_compare_add_point(WORD card, long pos, WORD dir,  WORD action, long actpara);
PCI408_API long __stdcall PCI408_compare_get_current_point(WORD card);
PCI408_API long __stdcall PCI408_compare_get_points_runned(WORD card);
PCI408_API long __stdcall PCI408_compare_get_points_remained(WORD card);


//多组位置比较 带Extern函数
PCI408_API DWORD __stdcall PCI408_compare_set_pulsetimes_Extern(WORD card, WORD queue, WORD itimes);
PCI408_API DWORD __stdcall PCI408_compare_set_filter_Extern(WORD card, DWORD frequency);
PCI408_API DWORD __stdcall PCI408_compare_get_filter_Extern(WORD card, DWORD* frequency);
PCI408_API DWORD __stdcall PCI408_compare_config_Extern(WORD card, WORD queue,WORD enable, WORD axis,  WORD cmp_source);
PCI408_API DWORD __stdcall PCI408_compare_get_config_Extern(WORD card, WORD queue,WORD* enable, WORD* axis,  WORD* cmp_source);

PCI408_API DWORD __stdcall PCI408_compare_clear_points_Extern(WORD card, WORD queue);
PCI408_API DWORD __stdcall PCI408_compare_add_point_Extern(WORD card, WORD queue,long pos, WORD dir,  WORD action, long actpara);
PCI408_API long __stdcall PCI408_compare_get_current_point_Extern(WORD card, WORD queue);
PCI408_API long __stdcall PCI408_compare_get_points_runned_Extern(WORD card, WORD queue);
PCI408_API long __stdcall PCI408_compare_get_points_remained_Extern(WORD card, WORD queue);



//---------------------   编码器计数功能  ----------------------//
PCI408_API long __stdcall PCI408_get_encoder(WORD axis);
PCI408_API DWORD __stdcall PCI408_set_encoder(WORD axis,long encoder_value);

PCI408_API DWORD __stdcall PCI408_config_EZ_PIN(WORD axis,WORD ez_logic, WORD ez_mode);
PCI408_API DWORD __stdcall PCI408_get_config_EZ_PIN(WORD axis,WORD* ez_logic, WORD* ez_mode);

PCI408_API DWORD __stdcall PCI408_config_LTC_PIN(WORD axis,WORD ltc_logic, WORD ltc_mode);

PCI408_API DWORD __stdcall PCI408_config_latch_mode(WORD cardno, WORD all_enable);

PCI408_API long __stdcall PCI408_get_latch_value(WORD axis);
PCI408_API long __stdcall PCI408_get_latch_flag(WORD cardno);
PCI408_API DWORD __stdcall PCI408_reset_latch_flag(WORD cardno);

PCI408_API long __stdcall PCI408_get_counter_flag(WORD cardno);
PCI408_API DWORD __stdcall PCI408_reset_counter_flag(WORD cardno);

PCI408_API DWORD __stdcall PCI408_reset_clear_flag(WORD cardno);

PCI408_API DWORD __stdcall PCI408_triger_chunnel(WORD cardno, WORD num);
PCI408_API DWORD __stdcall PCI408_set_speaker_logic(WORD cardno, WORD logic);

PCI408_API DWORD __stdcall PCI408_get_speaker_logic(WORD cardno, WORD* logic);
PCI408_API DWORD __stdcall PCI408_get_config_latch_mode(WORD cardno, WORD* all_enable);

//软件限位功能
PCI408_API DWORD __stdcall PCI408_config_softlimit(WORD axis,WORD ON_OFF, WORD source_sel,WORD SL_action, long N_limit,long P_limit);
PCI408_API DWORD __stdcall PCI408_get_config_softlimit(WORD axis,WORD* ON_OFF, WORD* source_sel,WORD* SL_action,long* N_limit,long* P_limit);


//连续插补函数
PCI408_API DWORD  __stdcall PCI408_conti_lines(WORD axisNum, WORD *piaxisList,
    long *pPosList, WORD posi_mode);

PCI408_API DWORD  __stdcall PCI408_conti_arc(WORD *axis, long *rel_pos, long *rel_cen, WORD arc_dir,  WORD posi_mode);

PCI408_API DWORD  __stdcall PCI408_conti_restrain_speed(WORD card, double v);

PCI408_API  DWORD  __stdcall PCI408_conti_change_speed_ratio(WORD card, double percent);
PCI408_API  double    __stdcall PCI408_conti_get_current_speed_ratio(WORD card);

PCI408_API  DWORD  __stdcall PCI408_conti_set_mode(WORD card, WORD conti_mode, double conti_vl, double conti_para, double filter);
PCI408_API  DWORD  __stdcall PCI408_conti_get_mode(WORD card, WORD* conti_mode, double* conti_vl, double* conti_para, double* filter);

PCI408_API DWORD  __stdcall PCI408_conti_open_list(WORD axisNum, WORD *piaxisList);
PCI408_API DWORD  __stdcall PCI408_conti_close_list(WORD card);
PCI408_API DWORD  __stdcall PCI408_conti_check_remain_space(WORD card);

PCI408_API DWORD  __stdcall PCI408_conti_decel_stop_list(WORD card);
PCI408_API DWORD  __stdcall PCI408_conti_sudden_stop_list(WORD card);
PCI408_API DWORD  __stdcall PCI408_conti_pause_list(WORD card);
PCI408_API DWORD  __stdcall PCI408_conti_start_list(WORD card);

PCI408_API long __stdcall PCI408_conti_read_current_mark(WORD card);
PCI408_API DWORD  __stdcall PCI408_conti_extern_lines(WORD axisNum, WORD *piaxisListw,
                                               long *pPosList, WORD posi_mode, long imark);
PCI408_API DWORD  __stdcall PCI408_conti_extern_arc(WORD *axis, long *rel_pos, long *rel_cen, WORD arc_dir,WORD posi_mode, long imark);


//相对螺旋插补运动函数
PCI408_API  DWORD  __stdcall PCI408_rel_helix_move(WORD card, WORD* axisList, long *rel_pos,long *rel_cen, long height, WORD

arc_dir);
//绝对螺旋插补运动函数
PCI408_API  DWORD  __stdcall PCI408_helix_move(WORD card, WORD* axisList, long *target_pos,long *cen_pos,long height, WORD

arc_dir);

//相对螺旋插补运动函数, 只在连续插补中调用
PCI408_API  DWORD  __stdcall PCI408_conti_rel_helix_move_extern(WORD card, WORD* axisList,long *rel_pos,long *rel_cen, long height,

WORD arc_dir, long imark);

//绝对螺旋插补运动函数, 只在连续插补中调用
PCI408_API  DWORD  __stdcall PCI408_conti_helix_move_extern(WORD card,WORD* axisList,long *target_pos,long *cen_pos,long height,

WORD arc_dir, long imark);

PCI408_API DWORD __stdcall PCI408_set_gear_mode(WORD axis,WORD masterAxis, double ratio, WORD source);

PCI408_API DWORD __stdcall PCI408_get_gear_mode(WORD axis,WORD* masterAxis, double* ratio, WORD* source);

PCI408_API DWORD __stdcall PCI408_gear_move(WORD axis );

PCI408_API int __stdcall  PCI408_conti_clear_all_outbit(WORD card);

PCI408_API int __stdcall  PCI408_conti_add_outbit(WORD card, WORD ioNum, WORD IoState);

PCI408_API int __stdcall  PCI408_conti_get_outbit_space(WORD card);


PCI408_API double __stdcall PCI408_conti_get_total_length(WORD card);

//读取
PCI408_API double __stdcall  PCI408_conti_get_remain_length(WORD card);
PCI408_API DWORD __stdcall PCI408_conti_SetContiPrecision(double Precision);
 //PCI408_conti_check_remain_space_sub(card)
//PC库错误码
enum ERR_CODE_DMC
{
    ERR_NOERR = 0,          //成功
    ERR_UNKNOWN = 1,
    ERR_PARAERR = 2,

    ERR_TIMEOUT = 3,
    ERR_CONTROLLERBUSY = 4,
    ERR_CONNECT_TOOMANY = 5,

    ERR_CONTILINE = 6,
    ERR_CANNOT_CONNECTETH = 8,
    ERR_HANDLEERR = 9,
    ERR_SENDERR = 10,
    ERR_FIRMWAREERR = 12, //固件文件错误
    ERR_FIRMWAR_MISMATCH = 14, //固件不匹配

    ERR_FIRMWARE_INVALID_PARA    = 20,  //固件参数错误
    ERR_FIRMWARE_PARA_ERR    = 20,  //固件参数错误2
    ERR_FIRMWARE_STATE_ERR    = 22, //固件当前状态不允许操作
    ERR_FIRMWARE_LIB_STATE_ERR    = 22, //固件当前状态不允许操作2
    ERR_FIRMWARE_CARD_NOT_SUPPORT    = 24,  //固件不支持的功能 控制器不支持的功能
    ERR_FIRMWARE_LIB_NOTSUPPORT    = 24,    //固件不支持的功能2
};

#ifdef __cplusplus
}
#endif

#endif




















