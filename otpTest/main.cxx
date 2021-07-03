#include "TOTP.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("\nThis program is used to verify the one-time dynamic password (TOTP), the algorithm adopts SHA1 to return 0 for success, and -1 for failure.\n");
		printf("Using:%s otp_password\n", argv[0]);
		printf("example:%s 123456\n\n", argv[0]);
		return -1;
	}

	if (0 == TOTP::ET_CheckPwdz201(argv[1]))
	{
		printf("\nVerified successfully!\n\n");
		return 0;
	}

	printf("\nVerified failed!\n\n");

	return 0;
}
