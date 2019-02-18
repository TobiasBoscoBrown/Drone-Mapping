#pragma once

bool is_Number_Zero(float f) {
	if (f == 0){
		return true;
	}
	else {
		return false;
	}
}

bool is_Number_Equal_Less_Zero(float f) {
	if (f <= 0) {
		return true;
	}
	else {
		return false;
	}
}

bool is_Char_a(char f) {
	if (f == 'a') {
		return true;
	}
	else {
		return false;
	}
}

bool is_Char_a_b(char f) {
	if (f == ('a' || 'b')) {
		return true;
	}
	else {
		return false;
	}
}

bool is_Char_a_b_c(char f) {
	if (f == ('a' || 'b' || 'c')) {
		return true;
	}
	else {
		return false;
	}
}

bool is_Char_a_b_c_d(char f) {
	if (f == ('a' || 'b' || 'c' || 'd')) {
		return true;
	}
	else {
		return false;
	}
}

bool is_Char_a_b_c_d_e(char f) {
	if (f == ('a' || 'b' || 'c' || 'd' || 'e')) {
		return true;
	}
	else {
		return false;
	}
}