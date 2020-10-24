################################################################
# _                           _              
#| |    ___  ___      _______| |__  _ __ ___ 
#| |   / _ \/ _ \____|_  / __| '_ \| '__/ __|
#| |__|  __/  __/_____/ /\__ \ | | | | | (__ 
#|_____\___|\___|    /___|___/_| |_|_|  \___|
#
#
#Author:lee-shun
#
#Email:lee970802@163.com
#
################################################################
# If you come from bash you might have to change your $PATH.
# export PATH=$HOME/bin:/usr/local/bin:$PATH

# Path to your oh-my-zsh installation.
export ZSH=$HOME/.oh-my-zsh

# Set name of the theme to load --- if set to "random", it will
# load a random theme each time oh-my-zsh is loaded, in which case,
# to know which specific one was loaded, run: echo $RANDOM_THEME
# See https://github.com/ohmyzsh/ohmyzsh/wiki/Themes
# ZSH_THEME="agnoster"
#ZSH_THEME="powerline"
ZSH_THEME="robbyrussell"
# Set list of themes to pick from when loading at random
# Setting this variable when ZSH_THEME=random will cause zsh to load
# a theme from this variable instead of looking in ~/.oh-my-zsh/themes/
# If set to an empty array, this variable will have no effect.
# ZSH_THEME_RANDOM_CANDIDATES=( "robbyrussell" "agnoster" )

# Uncomment the following line to use case-sensitive completion.
# CASE_SENSITIVE="true"

# Uncomment the following line to use hyphen-insensitive completion.
# Case-sensitive completion must be off. _ and - will be interchangeable.
# HYPHEN_INSENSITIVE="true"

# Uncomment the following line to disable bi-weekly auto-update checks.
# DISABLE_AUTO_UPDATE="true"

# Uncomment the following line to automatically update without prompting.
# DISABLE_UPDATE_PROMPT="true"

# Uncomment the following line to change how often to auto-update (in days).
# export UPDATE_ZSH_DAYS=13

# Uncomment the following line if pasting URLs and other text is messed up.
# DISABLE_MAGIC_FUNCTIONS=true

# Uncomment the following line to disable colors in ls.
# DISABLE_LS_COLORS="true"

# Uncomment the following line to disable auto-setting terminal title.
# DISABLE_AUTO_TITLE="true"

# Uncomment the following line to enable command auto-correction.
# ENABLE_CORRECTION="true"

# Uncomment the following line to display red dots whilst waiting for completion.
# COMPLETION_WAITING_DOTS="true"

# Uncomment the following line if you want to disable marking untracked files
# under VCS as dirty. This makes repository status check for large repositories
# much, much faster.
# DISABLE_UNTRACKED_FILES_DIRTY="true"

# Uncomment the following line if you want to change the command execution time
# stamp shown in the history command output.
# You can set one of the optional three formats:
# "mm/dd/yyyy"|"dd.mm.yyyy"|"yyyy-mm-dd"
# or set a custom format using the strftime function format specifications,
# see 'man strftime' for details.
 HIST_STAMPS="mm/dd/yyyy"

# Would you like to use another custom folder than $ZSH/custom?
# ZSH_CUSTOM=/path/to/new-custom-folder

# Which plugins would you like to load?
# Standard plugins can be found in ~/.oh-my-zsh/plugins/*
# Custom plugins may be added to ~/.oh-my-zsh/custom/plugins/
# Example format: plugins=(rails git textmate ruby lighthouse)
# Add wisely, as too many plugins slow down shell startup.
plugins=(
	git
    zsh-autosuggestions
    zsh-syntax-highlighting
    z)

source $ZSH/oh-my-zsh.sh

# User configuration

# export MANPATH="/usr/local/man:$MANPATH"

# You may need to manually set your language environment
# export LANG=en_US.UTF-8

# Preferred editor for local and remote sessions
# if [[ -n $SSH_CONNECTION ]]; then
#   export EDITOR='vim'
# else
#   export EDITOR='mvim'
# fi
export EDITOR=nvim

# Compilation flags
# export ARCHFLAGS="-arch x86_64"
# Set personal aliases, overriding those provided by oh-my-zsh libs,
# plugins, and themes. Aliases can be placed here, though oh-my-zsh
# users are encouraged to define aliases within the ZSH_CUSTOM folder.
# For a full list of active aliases, run `alias`.
#
# Example aliases
# alias zshconfig="mate ~/.zshrc"
# alias ohmyzsh="mate ~/.oh-my-zsh"


#基本映射
alias vim="nvim"

alias Q="exit"
alias cl="clear"

alias cd=' cd'
alias ..=' cd ..; ls'
alias ...=' cd ..; cd ..; ls'
alias ....=' cd ..; cd ..; cd ..; ls'
alias cd..='..'
alias cd...='...'
alias cd....='....'

alias update="sudo apt update"
alias canupgrade="sudo apt list --upgradable"
alias upgrade="sudo apt upgrade"
alias install="sudo apt install"
alias remove="sudo apt remove"
alias autoremove="sudo apt autoremove"

alias getinstall="sudo apt-get install"
alias getupdate="sudo apt-get update"
alias getremove="sudo apt-get remove"

#编辑文件
alias zshrc="vim ~/.zshrc"
alias vimrc="cd ~/.config/nvim/&& vim init.vim"
alias fixwing="cd ~/catkin_ws/src/fixed_wing_formation_control&&ranger"
alias codefixwing="code ~/catkin_ws/src/fixed_wing_formation_control"
alias notes="vim ~/vimwiki"

#开启连接
#alias v2="sudo service v2ray start"
#alias v2_status="sudo service v2ray status"
#alias v2_stop="sudo service v2ray stop"
#alias v2_re="sudo service v2ray restart"


#开启代理
#alias privox="sudo service privoxy start"
#alias privox_status="sudo service privoxy status"
#alias privox_stop="sudo service privoxy stop"
#alias privox_re="sudo service privoxy restart"

#alias scoks2https=" export https_proxy='http://localhost:8118'"
#alias scoks2http=" export http_proxy='http://localhost:8118'"

#默认编辑器
#export nvim="/usr/local/bin/nvim"
export EDITOR='nvim'

#MATLAB2019
#alias matlab="roscd fixed_wing_formation_control&&~/MATLAB/R2018b/bin/matlab"

#福昕pdf阅读器
#alias pdf="~/FOXITPDF/FoxitReader"

#添加lazygit
alias lg="lazygit"

#添加neofetch
alias sys="neofetch"

#添加ranger
alias R="ranger"
export RANGER_LOAD_DEFAULT_RC=FALSE

#添加tmux
alias tsnew="tmux new -s "
alias tl="tmux list-sessions"
alias tat="tmux attach -t"
alias tks="tmux kill-session -t"
alias tkw="tmux kill-window -t"
alias tkp="tmux kill-pane -t"
#ccat
#alias cat="ccat"

#kitty

#小彩蛋
#fortune | cowsay

#texlive2020
export MANPATH=${MANPATH}:/usr/local/texlive/2020/texmf-dist/doc/man
export INFOPATH=${INFOPATH}:/usr/local/texlive/2020/texmf-dist/doc/info
export PATH=${PATH}:/usr/local/texlive/2020/bin/x86_64-linux


#加速粘贴速度
# This speeds up pasting w/ autosuggest
# https://github.com/zsh-users/zsh-autosuggestions/issues/238
pasteinit() {
  OLD_SELF_INSERT=${${(s.:.)widgets[self-insert]}[2,3]}
  zle -N self-insert url-quote-magic # I wonder if you'd need `.url-quote-magic`?
}

pastefinish() {
  zle -N self-insert $OLD_SELF_INSERT
}
zstyle :bracketed-paste-magic paste-init pasteinit
zstyle :bracketed-paste-magic paste-finish pastefinish


#使用vim模式
bindkey -v
#改变光标状态
function zle-keymap-select {
	if [[ ${KEYMAP} == vicmd ]] || [[ $1 = 'block' ]]; then
		echo -ne '\e[1 q'
	elif [[ ${KEYMAP} == main ]] || [[ ${KEYMAP} == viins ]] || [[ ${KEYMAP} = '' ]] || [[ $1 = 'beam' ]]; then
		echo -ne '\e[5 q'
  fi
}
zle -N zle-keymap-select

# Use beam shape cursor on startup.
echo -ne '\e[5 q'

# Use beam shape cursor for each new prompt.
preexec() {
	echo -ne '\e[5 q'
}

_fix_cursor() {
	echo -ne '\e[5 q'
}
precmd_functions+=(_fix_cursor)


zle -N zle-line-init
zle -N zle-keymap-select

KEYTIMEOUT=1

# 配置ros
#source /opt/ros/kinetic/setup.zsh
#source /opt/ros/melodic/setup.zsh
source /opt/ros/noetic/setup.zsh
# 配置catkin_ws
source ~/catkin_ws/devel/setup.zsh
#movit
# source ~/ws_moveit/devel/setup.zsh


#配置Gazebo&&PX4
#export PX4_SIM_SPEED_FACTOR=2
#export PX4_HOME_LAT=39.9891248
#export PX4_HOME_LON=116.3558232
#export PX4_HOME_ALT=0.0;

#1.10.2
#source ~/src/Firmware/Tools/setup_gazebo.bash ~/src/Firmware/ ~/src/Firmware/build/px4_sitl_default
#export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:~/src/Firmware/:~/src/Firmware/Tools/sitl_gazebo

#1.9.2
#source ~/src/Firmwarelee1.9.2/Tools/setup_gazebo.bash ~/src/Firmwarelee1.9.2/ ~/src/Firmwarelee1.9.2/build/px4_sitl_default
#export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:~/src/Firmwarelee1.9.2/:~/src/Firmwarelee1.9.2/Tools/sitl_gazebo


## <<< conda initialize <<<
##配置Conda
## >>> conda initialize >>>
## !! Contents within this block are managed by 'conda init' !!
#__conda_setup="$('/home/lee/anaconda3/bin/conda' 'shell.bash' 'hook' 2> /dev/null)"
#if [ $? -eq 0 ]; then
#    eval "$__conda_setup"
#else
#    if [ -f "/home/lee/anaconda3/etc/profile.d/conda.sh" ]; then
#        . "/home/lee/anaconda3/etc/profile.d/conda.sh"
#    else
#        export PATH="/home/lee/anaconda3/bin:$PATH"
#    fi
#fi
#unset __conda_setup
##
## <<< conda initialize <<<


#fzf
[ -f ~/.fzf.zsh ] && source ~/.fzf.zsh

#fzf-settings
export FZF_DEFAULT_OPTS='--bind ctrl-j:down,ctrl-k:up --preview "[[ $(file --mime {}) =~ binary ]] && echo {} is a binary file || (ccat --color=always {} || highlight -O ansi -l {} || cat {}) 2> /dev/null | head -500"'
export FZF_DEFAULT_COMMAND='fdfind'
export FZF_COMPLETION_TRIGGER='\'
export FZF_TMUX=1
export FZF_TMUX_HEIGHT='80%'
export fzf_preview_cmd='[[ $(file --mime {}) =~ binary ]] && echo {} is a binary file || (ccat --color=always {} || highlight -O ansi -l {} || cat {}) 2> /dev/null | head -500'

# Use fd (https://github.com/sharkdp/fd) instead of the default find
# command for listing path candidates.
# - The first argument to the function ($1) is the base path to start traversal
# - See the source code (completion.{bash,zsh}) for the details.
_fzf_compgen_path() {
  fdfind --hidden --follow --exclude ".git" . "$1"
}

# Use fd to generate the list for directory completion
_fzf_compgen_dir() {
  fdfind --type d --hidden --follow --exclude ".git" . "$1"
}

# (EXPERIMENTAL) Advanced customization of fzf options via _fzf_comprun function
# - The first argument to the function is the name of the command.
# - You should make sure to pass the rest of the arguments to fzf.
_fzf_comprun() {
  local command=$1
  shift

  case "$command" in
    cd)           fzf "$@" --preview 'tree -C {} | head -200' ;;
    export|unset) fzf "$@" --preview "eval 'echo \$'{}" ;;
    ssh)          fzf "$@" --preview 'dig {}' ;;
    *)            fzf "$@" ;;
  esac
}
