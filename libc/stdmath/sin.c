// WARNING: THIS FILE IS PARTLY MACHINE-GENERATED
#include <trigonometric_functions.h>
double sin(double x)
{
	int sign = 1;
	
	if (x < 0) // 70.5 > 0, пропускаем
	{
		sign *= -1;//а это зачем?Если x < 0, то sin(x) = -sin(-x) понятно все 
		x *= -1;// вроде немного отлагало но все равно медленно/ интернет у меня не очень. Вайфай отваливается частоА может код тяжелый Да не все таки я не понял, к)ак быть с sin (70,5
	}
	
	if ((int)(x/180)%2 != 0) // Это тоже не выполнится
	{
		sign *= -1;
	}
	x -= (int)(x/180) * 180;//что это приводит x к промежутку [0; 180] (int)(x/180)*180=x
	
	/*
	
	x = 270.0;
	(int)(x/180) = (int)1.5 = 1
	1*180 = 180
	270.0 - 180 = 90.0      (int) округление в меньшую сторону для положительных чисел, и в большую для отрицательных. (int)5.7 = 5, (int)(-6.72) = -6  ясно
	Что дальше делаем? Операционнку развиваем. Сделаем поддержку RAMFS? Только я пока не знаю что это . Файловая система в оперативной памяти. Хмм ну го
	
	*/
	
	// Сейчас x == 70.5
	
	double ret = 0;
	switch((int)x)  // (int)70.5 == 70 ой блин точно не заметил
	{
		case 0: ret = 0.000000000; break;
		case 1: ret = 0.017452406; break;
		case 2: ret = 0.034899497; break;
		case 3: ret = 0.052335956; break; // Ты здесь? да о, отлагало. Я на другую сетку переключился Вроде эта получше. 
		case 4: ret = 0.069756474; break;
		case 5: ret = 0.087155743; break;
		case 6: ret = 0.104528463; break;
		case 7: ret = 0.121869343; break;
		case 8: ret = 0.139173101; break;
		case 9: ret = 0.156434465; break;
		case 10: ret = 0.173648178; break;
		case 11: ret = 0.190808995; break;
		case 12: ret = 0.207911691; break;
		case 13: ret = 0.224951054; break;
		case 14: ret = 0.241921896; break;
		case 15: ret = 0.258819045; break;
		case 16: ret = 0.275637356; break;
		case 17: ret = 0.292371705; break;
		case 18: ret = 0.309016994; break;
		case 19: ret = 0.325568154; break;
		case 20: ret = 0.342020143; break;
		case 21: ret = 0.358367950; break;
		case 22: ret = 0.374606593; break;
		case 23: ret = 0.390731128; break;
		case 24: ret = 0.406736643; break;
		case 25: ret = 0.422618262; break;
		case 26: ret = 0.438371147; break;
		case 27: ret = 0.453990500; break;
		case 28: ret = 0.469471563; break;
		case 29: ret = 0.484809620; break;
		case 30: ret = 0.500000000; break;
		case 31: ret = 0.515038075; break;
		case 32: ret = 0.529919264; break;
		case 33: ret = 0.544639035; break;
		case 34: ret = 0.559192903; break;
		case 35: ret = 0.573576436; break;
		case 36: ret = 0.587785252; break;
		case 37: ret = 0.601815023; break;
		case 38: ret = 0.615661475; break;
		case 39: ret = 0.629320391; break;
		case 40: ret = 0.642787610; break;
		case 41: ret = 0.656059029; break;
		case 42: ret = 0.669130606; break;
		case 43: ret = 0.681998360; break;
		case 44: ret = 0.694658370; break;
		case 45: ret = 0.707106781; break;
		case 46: ret = 0.719339800; break;
		case 47: ret = 0.731353702; break;
		case 48: ret = 0.743144825; break;
		case 49: ret = 0.754709580; break;
		case 50: ret = 0.766044443; break;
		case 51: ret = 0.777145961; break;
		case 52: ret = 0.788010754; break;
		case 53: ret = 0.798635510; break;
		case 54: ret = 0.809016994; break;
		case 55: ret = 0.819152044; break;
		case 56: ret = 0.829037573; break;
		case 57: ret = 0.838670568; break;
		case 58: ret = 0.848048096; break;
		case 59: ret = 0.857167301; break;
		case 60: ret = 0.866025404; break;
		case 61: ret = 0.874619707; break;
		case 62: ret = 0.882947593; break;
		case 63: ret = 0.891006524; break;
		case 64: ret = 0.898794046; break;
		case 65: ret = 0.906307787; break;
		case 66: ret = 0.913545458; break;
		case 67: ret = 0.920504853; break;
		case 68: ret = 0.927183855; break;
		case 69: ret = 0.933580426; break;
		case 70: ret = 0.939692621; break;
		case 71: ret = 0.945518576; break;
		case 72: ret = 0.951056516; break;
		case 73: ret = 0.956304756; break;
		case 74: ret = 0.961261696; break;
		case 75: ret = 0.965925826; break;
		case 76: ret = 0.970295726; break;
		case 77: ret = 0.974370065; break;
		case 78: ret = 0.978147601; break;
		case 79: ret = 0.981627183; break;
		case 80: ret = 0.984807753; break;
		case 81: ret = 0.987688341; break;
		case 82: ret = 0.990268069; break;
		case 83: ret = 0.992546152; break;
		case 84: ret = 0.994521895; break;
		case 85: ret = 0.996194698; break;
		case 86: ret = 0.997564050; break;
		case 87: ret = 0.998629535; break;
		case 88: ret = 0.999390827; break;
		case 89: ret = 0.999847695; break;
		case 90: ret = 1.000000000; break;
		case 91: ret = 0.999847695; break;
		case 92: ret = 0.999390827; break;
		case 93: ret = 0.998629535; break;
		case 94: ret = 0.997564050; break;
		case 95: ret = 0.996194698; break;
		case 96: ret = 0.994521895; break;
		case 97: ret = 0.992546152; break;
		case 98: ret = 0.990268069; break;
		case 99: ret = 0.987688341; break;
		case 100: ret = 0.984807753; break;
		case 101: ret = 0.981627183; break;
		case 102: ret = 0.978147601; break;
		case 103: ret = 0.974370065; break;
		case 104: ret = 0.970295726; break;
		case 105: ret = 0.965925826; break;
		case 106: ret = 0.961261696; break;
		case 107: ret = 0.956304756; break;
		case 108: ret = 0.951056516; break;
		case 109: ret = 0.945518576; break;
		case 110: ret = 0.939692621; break;
		case 111: ret = 0.933580427; break;
		case 112: ret = 0.927183855; break;
		case 113: ret = 0.920504853; break;
		case 114: ret = 0.913545458; break;
		case 115: ret = 0.906307787; break;
		case 116: ret = 0.898794046; break;
		case 117: ret = 0.891006524; break;
		case 118: ret = 0.882947593; break;
		case 119: ret = 0.874619707; break;
		case 120: ret = 0.866025404; break;
		case 121: ret = 0.857167301; break;
		case 122: ret = 0.848048096; break;
		case 123: ret = 0.838670568; break;
		case 124: ret = 0.829037573; break;
		case 125: ret = 0.819152044; break;
		case 126: ret = 0.809016994; break;
		case 127: ret = 0.798635510; break;
		case 128: ret = 0.788010754; break;
		case 129: ret = 0.777145961; break;
		case 130: ret = 0.766044443; break;
		case 131: ret = 0.754709580; break;
		case 132: ret = 0.743144826; break;
		case 133: ret = 0.731353702; break;
		case 134: ret = 0.719339800; break;
		case 135: ret = 0.707106781; break;
		case 136: ret = 0.694658371; break;
		case 137: ret = 0.681998360; break;
		case 138: ret = 0.669130606; break;
		case 139: ret = 0.656059029; break;
		case 140: ret = 0.642787610; break;
		case 141: ret = 0.629320391; break;
		case 142: ret = 0.615661475; break;
		case 143: ret = 0.601815023; break;
		case 144: ret = 0.587785252; break;
		case 145: ret = 0.573576436; break;
		case 146: ret = 0.559192904; break;
		case 147: ret = 0.544639035; break;
		case 148: ret = 0.529919264; break;
		case 149: ret = 0.515038075; break;
		case 150: ret = 0.500000000; break;
		case 151: ret = 0.484809620; break;
		case 152: ret = 0.469471563; break;
		case 153: ret = 0.453990500; break;
		case 154: ret = 0.438371147; break;
		case 155: ret = 0.422618262; break;
		case 156: ret = 0.406736643; break;
		case 157: ret = 0.390731129; break;
		case 158: ret = 0.374606593; break;
		case 159: ret = 0.358367950; break;
		case 160: ret = 0.342020143; break;
		case 161: ret = 0.325568155; break;
		case 162: ret = 0.309016994; break;
		case 163: ret = 0.292371705; break;
		case 164: ret = 0.275637356; break;
		case 165: ret = 0.258819045; break;//это у меня подвисает или у тебя? хз. щас посмотрим
		case 166: ret = 0.241921896; break;
		case 167: ret = 0.224951054; break;
		case 168: ret = 0.207911691; break;
		case 169: ret = 0.190808995; break;
		case 170: ret = 0.173648178; break;
		case 171: ret = 0.156434465; break;
		case 172: ret = 0.139173101; break;
		case 173: ret = 0.121869343; break;
		case 174: ret = 0.104528463; break;
		case 175: ret = 0.087155743; break;
		case 176: ret = 0.069756474; break;
		case 177: ret = 0.052335956; break;
		case 178: ret = 0.034899497; break;
		case 179: ret = 0.017452407; break;
		case 180: ret = 0.000000000; break; // Лень было писать нормальный алгоритм, поэтому тупо забил значения капец А если sin(1,5) = sin((int)1.5) = sin(1)
	}
	return sign*ret;
}
