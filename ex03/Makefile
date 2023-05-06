NAME        :=  At_least_this_beats_coffee-making
CC			:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98
INCLUDE		:=	-Iincludes
VPATH		:=	srcs
SRCS		:=	main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
OBJSDIR		:=	objs
OBJS		:=	$(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.o))
RM			:=	rm -rf

all: $(NAME)

$(NAME): $(OBJSDIR) $(OBJS)
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJSDIR)/%.o: %.cpp
	$(CC) $(INCLUDE) $(CXXFLAGS) -o $@ -c $<

objs:
	mkdir -p objs

clean:
	$(RM) $(OBJSDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
