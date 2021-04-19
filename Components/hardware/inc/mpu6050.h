/**
 * @file mpu6050.h
 * @author Quentin Bakrim (quentin.bakrim@hotmail.fr)
 * @brief 
 * @version 0.2
 * @date 2021-04-11
 * 
 * Mines Space
 * 
 */

#ifndef __MPU6050_H__
#define __MPU6050_H__

/* ------------------------------------------------------------- --
   Includes
-- ------------------------------------------------------------- */
#include <stdint.h>
#include "i2c.h"


/* ------------------------------------------------------------- --
   Defines
-- ------------------------------------------------------------- */
#define MPU6050_WHO_AM_I_REG 		0x75
#define MPU6050_PWR_MGMT_1_REG 	0x6B
#define MPU6050_SMPLRT_DIV_REG 	0x19
#define MPU6050_ACCEL_CONFIG_REG 0x1C
#define MPU6050_ACCEL_XOUT_H_REG 0x3B
#define MPU6050_TEMP_OUT_H_REG 	0x41
#define MPU6050_GYRO_CONFIG_REG 	0x1B
#define MPU6050_GYRO_XOUT_H_REG 	0x43

#define MPU6050_ADDR 				0x69 << 1 	/* ( << 1 because of the R/W bit */

#define RAD_TO_DEG 					57.295779513082320876798154814105


/* ------------------------------------------------------------- --
   Enumerates
-- ------------------------------------------------------------- */
/* Accel full scale range settings */
typedef enum
{
	MPU6050_AFS_2G = 0,
	MPU6050_AFS_4G = 1,
	MPU6050_AFS_8G = 2,
	MPU6050_AFS_16G = 3
}MPU6050_AccelFullScale;

/* gyro full scale range settings */
typedef enum
{
	MPU6050_GFS_250_DEG_S = 0,
	MPU6050_GFS_500_DEG_S = 1,
	MPU6050_GFS_1000_DEG_S = 2,
	MPU6050_GFS_2000_DEG_S = 3
}MPU6050_GyroFullScale;

/* sample rate settings */
typedef enum
{							   /* Sample Rate = Gyroscope Output Rate / (1 + SMPLRT_DIV) */
	MPU6050_SR_8KHZ = 1,	/* Gyroscope Output Rate = 8kHz when the DLPF is disabled (DLPF_CFG= 0 or 7), and 1kHz when the DLPF is enabled */
	MPU6050_SR_4KHZ = 3,
	MPU6050_SR_2KHZ = 5,
	MPU6050_SR_1KHZ = 7,
}MPU6050_SampleRate;


/* ------------------------------------------------------------- --
   Structures
-- ------------------------------------------------------------- */
/* configuration structure */
typedef struct
{
	MPU6050_AccelFullScale AFS;
	MPU6050_GyroFullScale GFS;
	MPU6050_SampleRate SR;
}MPU6050_config_t;

/* MPU6050 handle structure */
typedef struct {

    int16_t Accel_X_RAW;
    int16_t Accel_Y_RAW;
    int16_t Accel_Z_RAW;
    double Ax;
    double Ay;
    double Az;

    int16_t Gyro_X_RAW;
    int16_t Gyro_Y_RAW;
    int16_t Gyro_Z_RAW;
    double Gx;
    double Gy;
    double Gz;

    int16_t Temperature_RAW;
    float Temperature;

    MPU6050_config_t config;

} MPU6050_t;


/* ------------------------------------------------------------- --
   Prototypes
-- ------------------------------------------------------------- */
uint8_t MPU6050_Init();
uint8_t MPU6050_Read_Accel();
uint8_t MPU6050_Read_Gyro();
uint8_t MPU6050_Read_Temp();
uint8_t MPU6050_Read_All();


#endif /* INC_GY521_H_ */


/* ------------------------------------------------------------- --
   End of files
-- ------------------------------------------------------------- */
