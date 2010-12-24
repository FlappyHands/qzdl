/*
 * This file is part of qZDL
 * Copyright (C) 2007-2010  Cody Harris
 * 
 * qZDL is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
#include "ZDMFlagCheckbox.h"

ZDMFlagCheckbox::ZDMFlagCheckbox(int dmvalue, int highOn, QString text, QWidget *parent):QCheckBox(text,parent){
	logic = highOn;
	value = dmvalue;
	setValue(0);
}

void ZDMFlagCheckbox::setValue(int value){
	int msk = value & this->value;
	if(logic && msk){
		setCheckState(Qt::Checked);
	}else if(!logic && !msk){
		setCheckState(Qt::Checked);
	}else{
		setCheckState(Qt::Unchecked);
	}
}

int ZDMFlagCheckbox::getValue(){
	if(checkState() == Qt::Checked && logic){
		return value;
	}else if(checkState() == Qt::Unchecked && !logic){
		return value;
	}
	return 0;
}