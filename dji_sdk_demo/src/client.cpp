#include <ros/ros.h>
#include <dji_sdk/dji_sdk.h>
#include <dji_sdk/dji_drone.h>
#include <cstdlib>

#define HORIZ_ATT 0x00
#define HORIZ_VEL 0x40
#define HORIZ_POS 0x80
#define VERT_VEL 0x00
#define VERT_POS 0x10
#define VERT_TRU 0x20
#define YAW_ANG 0x00
#define YAW_RATE 0x08
#define HORIZ_GND 0x00
#define HORIZ_BODY 0x02
#define YAW_GND 0x00
#define YAW_BODY 0x01

static void Display_Main_Menu(void)
{
	printf("\r\n");
	printf("----------- < Main menu > ----------\r\n\r\n");
	printf("[a] Request to obtain control\n");
	printf("[b] Release control\n");
	printf("[c] Takeoff\n");
	printf("[d] Landing\n");
	printf("[e] Go home\n");
	printf("[f] Gimbal control sample\n");
	printf("[g] Attitude control sample\n");
	printf("[h] Draw circle sample\n");
	printf("[i] Draw square sample\n");
	printf("[j] Take a picture\n");
	printf("[k] Start video\n");
	printf("[l] Stop video\n");
	printf("[m] Exit\n");
	printf("\ninput a/b/c etc..then press enter key\r\n");
	printf("\nuse `rostopic echo` to query drone status\r\n");
	printf("----------------------------------------\r\n");
	printf("input: ");
}
int main(int argc, char **argv)
{
	int main_operate_code = 0;
	int temp32;
	bool valid_flag = false;
	bool err_flag = false;
	ros::init(argc, argv, "sdk_client");
	ROS_INFO("sdk_service_client_test");
	
	DJIDrone* drone = new DJIDrone("drone1");

	Display_Main_Menu();
	while(1)
	{
		temp32 = getchar();
		if(temp32 != 10)
		{
			if(temp32 >= 'a' && temp32 <= 'm' && valid_flag == false)
			{
				main_operate_code = temp32;
				valid_flag = true;
			}
			else
			{
				err_flag = true;
			}
			continue;
		}
		else
		{
			if(err_flag == true)
			{
				printf("input: ERROR\n");
				Display_Main_Menu();
				err_flag = valid_flag = false;
				continue;
			}
		}
		switch(main_operate_code)
		{
			case 'a':
				/* request control ability*/
				drone->request_sdk_permission_control();
				break;
			case 'b':
				/* release control ability*/
				drone->release_sdk_permission_control();
				break;
			case 'c':
				/* take off */
				drone->takeoff();
				break;
			case 'd':
				/* landing*/
				drone->landing();
				break;
			case 'e':
				/* go home*/
				drone->gohome();
				break;
			case 'f':
				/*gimbal test*/

				drone->gimbal_angle_control(0, 0, 0, 1800, 20);
				sleep(2);
				drone->gimbal_angle_control(0, 0, 0, -1800, 20);
				sleep(2);
				drone->gimbal_angle_control(0, 300, 0, 0, 20);
				sleep(2);
				drone->gimbal_angle_control(0, -300, 0, 0, 20);
				sleep(2);
				drone->gimbal_angle_control(0, 0, 300, 0, 20);
				sleep(2);
				drone->gimbal_angle_control(0, 0, -300, 0, 20);
				sleep(2);
				drone->gimbal_speed_control(0, 0, 200);
				sleep(2);
				drone->gimbal_speed_control(0, 0, -200);
				sleep(2);
				drone->gimbal_speed_control(0, 200, 0);
				sleep(2);
				drone->gimbal_speed_control(0, -200, 0);
				sleep(2);
				drone->gimbal_angle_control(0, 0, 0, 0, 20);
				break;

			case 'g':
				/* attitude control sample*/
				// srv_action.request.action=4;
				// drone_action_client.call(srv_action);
				// sleep(8);

				// srv_attitude.request.flag = 0x40;
				// srv_attitude.request.x = 0;
				// srv_attitude.request.y = 0;
				// srv_attitude.request.yaw = 0;
				// for(int i = 0; i < 100; i ++)
				// {
				// 	if(i < 90)
				// 		srv_attitude.request.z = 2.0;
				// 	else
				// 		srv_attitude.request.z = 0.0;
				// 	drone_attitude_client.call(srv_attitude);
				// 	usleep(20000);
				// }
				// sleep(1);

				// srv_attitude.request.flag = 0x40;
				// srv_attitude.request.y = 0;
				// srv_attitude.request.z = 0;
				// srv_attitude.request.yaw = 0;
				// for(int i = 0; i < 200; i ++)
				// {
				// 	if(i < 180)
				// 		srv_attitude.request.x = 2;
				// 	else
				// 		srv_attitude.request.x = 0;
				// 	drone_attitude_client.call(srv_attitude);
				// 	usleep(20000);
				// }
				// sleep(1);

				// srv_attitude.request.flag = 0x40;
				// srv_attitude.request.y = 0;
				// srv_attitude.request.z = 0;
				// srv_attitude.request.yaw = 0;
				// for(int i = 0; i < 200; i ++)
				// {
				// 	if(i < 180)
				// 		srv_attitude.request.x= -2;
				// 	else
				// 		srv_attitude.request.x= 0;
				// 	drone_attitude_client.call(srv_attitude);
				// 	usleep(20000);
				// }
				// sleep(1);

				// srv_attitude.request.flag = 0x40;
				// srv_attitude.request.x = 0;
				// srv_attitude.request.z = 0;
				// srv_attitude.request.yaw = 0;
				// for(int i = 0; i < 200; i ++)
				// {
				// 	if(i < 180)
				// 		srv_attitude.request.y = 2;
				// 	else
				// 		srv_attitude.request.y = 0;
				// 	drone_attitude_client.call(srv_attitude);
				// 	usleep(20000);
				// }
				// sleep(1);

				// srv_attitude.request.flag = 0x40;
				// srv_attitude.request.x = 0;
				// srv_attitude.request.z = 0;
				// srv_attitude.request.yaw = 0;
				// for(int i = 0; i < 200; i ++)
				// {
				// 	if(i < 180)
				// 		srv_attitude.request.y = -2;
				// 	else
				// 		srv_attitude.request.y = 0;
				// 	drone_attitude_client.call(srv_attitude);
				// 	usleep(20000);
				// }
				// sleep(1);

				// srv_attitude.request.flag = 0x40;
				// srv_attitude.request.x = 0;
				// srv_attitude.request.y = 0;
				// srv_attitude.request.yaw = 0;
				// for(int i = 0; i < 200; i ++)
				// {
				// 	if(i < 180)
				// 		srv_attitude.request.z = 0.5;
				// 	else
				// 		srv_attitude.request.z = 0;
				// 	drone_attitude_client.call(srv_attitude);
				// 	usleep(20000);
				// }
				// sleep(1);

				// srv_attitude.request.flag = 0x40;
				// srv_attitude.request.x = 0;
				// srv_attitude.request.y = 0;
				// srv_attitude.request.yaw = 0;
				// for(int i = 0; i < 200; i ++)
				// {
				// 	if(i < 180)
				// 		srv_attitude.request.z = -0.5;
				// 	else
				// 		srv_attitude.request.z = 0;
				// 	drone_attitude_client.call(srv_attitude);
				// 	usleep(20000);
				// }
				// sleep(1);

				// srv_attitude.request.flag = 0xA;
				// srv_attitude.request.x = 0;
				// srv_attitude.request.y = 0;
				// srv_attitude.request.z = 0;
				// for(int i = 0; i < 200; i ++)
				// {
				// 	if(i < 180)
				// 		srv_attitude.request.yaw = 90;
				// 	else
				// 		srv_attitude.request.yaw = 0;
				// 	drone_attitude_client.call(srv_attitude);
				// 	usleep(20000);
				// }
				// sleep(1);

				// srv_attitude.request.flag = 0xA;
				// srv_attitude.request.x = 0;
				// srv_attitude.request.y = 0;
				// srv_attitude.request.z = 0;
				// for(int i = 0; i < 200; i ++)
				// {
				// 	if(i < 180)
				// 		srv_attitude.request.yaw = -90;
				// 	else
				// 		srv_attitude.request.yaw = 0;
				// 	drone_attitude_client.call(srv_attitude);
				// 	usleep(20000);
				// }
				// sleep(1);


				// srv_action.request.action=1;
				// drone_action_client.call(srv_action);
				break;

			case 'h':
				/*draw circle sample*/
				// static float time = 0;
				// static float R = 2;
				// static float V = 2;
				// static float vx;
				// static float vy;
				// /* start to draw circle */
				// for(int i = 0; i < 300; i ++)
				// {
				// 	vx = V * sin((V/R)*time/50.0f);
				// 	vy = V * cos((V/R)*time/50.0f);
				// 	srv_attitude.request.flag = HORIZ_POS|VERT_VEL|YAW_ANG|HORIZ_BODY|YAW_BODY;
				// 	srv_attitude.request.x = vx;
				// 	srv_attitude.request.y = vy;
				// 	srv_attitude.request.z = 0;
				// 	srv_attitude.request.yaw = 0;
				// 	drone_attitude_client.call(srv_attitude);
				// 	usleep(20000);
				// 	time++;
				// }
				break;
			case 'i':
				/*draw square sample*/
				// for(int i = 0;i < 60;i++)
				// {
				// 	srv_attitude.request.flag = HORIZ_POS|VERT_VEL|YAW_ANG|HORIZ_BODY|YAW_BODY;
				// 	srv_attitude.request.x = 3;
				// 	srv_attitude.request.y = 3;
				// 	srv_attitude.request.z = 0;
				// 	srv_attitude.request.yaw = 0;
				// 	drone_attitude_client.call(srv_attitude);
				// 	usleep(20000);
				// }
				// for(int i = 0;i < 60;i++)
				// {
				// 	srv_attitude.request.flag = HORIZ_POS|VERT_VEL|YAW_ANG|HORIZ_BODY|YAW_BODY;
				// 	srv_attitude.request.x = -3;
				// 	srv_attitude.request.y = 3;
				// 	srv_attitude.request.z = 0;
				// 	srv_attitude.request.yaw = 0;
				// 	drone_attitude_client.call(srv_attitude);
				// 	usleep(20000);
				// }
				// for(int i = 0;i < 60;i++)
				// {
				// 	srv_attitude.request.flag = HORIZ_POS|VERT_VEL|YAW_ANG|HORIZ_BODY|YAW_BODY;
				// 	srv_attitude.request.x = -3;
				// 	srv_attitude.request.y = -3;
				// 	srv_attitude.request.z = 0;
				// 	srv_attitude.request.yaw = 0;
				// 	drone_attitude_client.call(srv_attitude);
				// 	usleep(20000);
				// }
				// for(int i = 0;i < 60;i++)
				// {
				// 	srv_attitude.request.flag = HORIZ_POS|VERT_VEL|YAW_ANG|HORIZ_BODY|YAW_BODY;
				// 	srv_attitude.request.x = 3;
				// 	srv_attitude.request.y = -3;
				// 	srv_attitude.request.z = 0;
				// 	srv_attitude.request.yaw = 0;
				// 	drone_attitude_client.call(srv_attitude);
				// 	usleep(20000);
				// }
				break;
			case 'j':
				/*take a picture*/
				drone->take_picture();
				break;
			case 'k':
				/*start video*/
				drone->record_video();
				break;
			case 'l':
				/*stop video*/
				drone->stop_video();
				break;
			case 'm':
				return 0;

			default:
				break;
		}
		main_operate_code = -1;
		err_flag = valid_flag = false;
		Display_Main_Menu();
	}
	return 0;
}