# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

void	send_signal(int pid, int bit)
{
	if (bit)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}

void	send_close(int pid)
{
	int	bitmask;

	bitmask = 1 << 7;
	while (bitmask)
	{
		send_signal(pid, 0);
		bitmask >>= 1;
		usleep(100);
	}
}

void	send_message(char *pid_str, char *str)
{
	int	bitmask;
	int	pid;

	pid = ft_atoi(pid_str);
	while (str && ft_strlen(str))
	{
		bitmask = 1 << 7;
		while (bitmask)
		{
			send_signal(pid, bitmask & *str);
			bitmask = bitmask >> 1;
			usleep(100);
		}
		str++;
	}
	send_close(pid);
}

void	receive_ack(int signo)
{
	if (signo == SIGUSR2)
		ft_putstr_fd("ACK Received!\n", 1);
	exit(0);
}

int	main(int argc, char *argv[])
{
	signal(SIGUSR2, receive_ack);
	if (argc != 3)
	{
		ft_putstr_fd("Usage : ", 1);
		write(1, argv[0], ft_strlen(argv[0]));
		ft_putstr_fd(" PID MESSAGE\n", 1);
		exit(0);
	}
	else if (ft_atoi(argv[1]) <= 100 || ft_atoi(argv[1]) > 99999)
	{
		ft_putstr_fd("PID must be in range (101 ~ 99999)\n", 1);
		exit(0);
	}
	else
		send_message(argv[1], argv[2]);
	sleep(1);
	ft_putstr_fd("Timeout over 1sec\n", 1);
	return (0);
}