#!/usr/bin/env bash

function move_output_to_top_dir() {

	case ${soc_dir} in
		sc2)
			SOC="32"
			;;
		t7)
			SOC="36"
			;;
		s4)
			SOC="37"
			;;
	esac

	if [ -f "${1}_${SOC}_bl30.bin" ]
	then
		rm "${1}_${SOC}_bl30.bin"
	fi

	if [ -f demos/amlogic/${arch_dir}/${soc_dir}/${board}/gcc/RTOSDemo.bin ]
	then
		mv demos/amlogic/${arch_dir}/${soc_dir}/${board}/gcc/RTOSDemo.bin ./${1}_${SOC}_bl30.bin
	fi
}

function coding_style_check() {
	if [ -d .git/hooks ]
	then
		if [ ! -f .git/hooks/pre-commit-old -a -f .git/hooks/pre-commit ]
		then
			cp .git/hooks/pre-commit .git/hooks/pre-commit-old
		fi
		cp scripts/amlogic/coding_style/pre-commit .git/hooks/
		chmod +x .git/hooks/pre-commit
	fi
}

source scripts/amlogic/mk.sh $1
coding_style_check
move_output_to_top_dir $1
