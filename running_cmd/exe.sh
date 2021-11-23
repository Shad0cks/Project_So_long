make -C ../ft_printf
make -C ../libft bonus
make -C ../minilibx
make -C ../Get_Next_Line
make -C ../Get_Next_Line 
make -C ../
gcc ../prog.a ../Get_Next_Line/GNL.a ../ft_printf/libftprintf.a ../libft/libft.a -L ../minilibx -lmlx -framework OpenGL -framework AppKit
./a.out