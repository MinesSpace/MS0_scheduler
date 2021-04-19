/*
 * motor.c
 *
 *  Created on: Mar 12, 2021
 *      Author: Quent
 */

#include "motor.h"

motor_t motor;

/**
 * @brief Init the motor struct
 * 
 */
void init_motor(void)
{
    motor.IT_flag = false;
    motor.DM_M1   = DIAG_MOTOR_OK;
    motor.DM_M2   = DIAG_MOTOR_OK;

    motor.CS_M1 = CURRENT_SENSING_OK;
    motor.CS_M2 = CURRENT_SENSING_OK;

    motor.HB_A_M1 = IN;
    motor.HB_B_M1 = IN;
    motor.HB_A_M2 = IN;
    motor.HB_B_M2 = IN;
}

void IT_flag_diag_motor()
{
    if(motor.IT_flag != true)
    {
        set_motor_IT_flag(true);
    }
}

void IT_routine_diag_motor()
{
    
}

/**
 * @brief Set the motor IT flag object
 * 
 * @param IT_flag 
 */
void set_motor_IT_flag(diag_motor_it_t IT_flag)
{
    motor.IT_flag = IT_flag;
}

/**
 * @brief Get the motor IT flag object
 * 
 * @return true 
 * @return false 
 */
diag_motor_it_t get_motor_IT_flag(void)
{
    return motor.IT_flag;
}

/**
 * @brief Set the diag motor status object
 * 
 * @param status 
 */
void set_diag_motor_status(select_motor_t motor_ID , diag_motor_t status)
{
    switch (motor_ID)
    {
    case M1 : motor.DM_M1 = status; break;
    case M2 : motor.DM_M2 = status; break;
    default :                       break;
    }
}

/**
 * @brief Get the diag motor status object
 * 
 * @return diag_motor_t 
 */
diag_motor_t get_diag_motor_status(select_motor_t motor_ID)
{
    diag_motor_t result;
    
    switch (motor_ID)
    {
    case M1 : result = motor.DM_M1; break;
    case M2 : result = motor.DM_M2; break;
    default :                       break;
    }

    return result;
}
