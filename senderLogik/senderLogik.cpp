#include "senderLogik.h"

int alarmTid(std::vector<char> &v)
{
int alarmTidIMs;
const int asciiConverter = 48; // bruges til at modulere vores chars til talværdier.

  for (int i = 0; i != v.size(); i++) 
  {
	  if (v[i] == 'N')
	  {
		  switch (v[i + 1]) 
      {
        case '1':
		alarmTidIMs = (((int)v[4] % asciiConverter) * 1000) + (((int)v[5] % asciiConverter) * 100) + (((int)v[7] % asciiConverter) * 10) + (((int)v[8] % asciiConverter) * 1);  // første enhed i ms
		break;
		
        case '2':
        alarmTidIMs = (((int)v[((4*2)-1)] % asciiConverter)*1000) + (((int)v[((5*2)-1)] % asciiConverter)*100) + (((int)v[(7*2)-1] % asciiConverter)*10) + (((int)v[(8*2)-1] % asciiConverter) *1);  // anden enhed i ms
        break;

        case '3':
        alarmTidIMs = (((int)v[(5*3)-1] % asciiConverter)*1000) + (((int)v[(6*3)-1] % asciiConverter)*100) + (((int)v[(8*3)-1] % asciiConverter)*10) + ((int)v[(9*3)-1] % asciiConverter *1); // tredje enhed i ms
        break;
	
		default:
			alarmTidIMs = (((int)v[4] % asciiConverter) * 1000) + (((int)v[5] % asciiConverter) * 100) + (((int)v[7] % asciiConverter) * 10) + (((int)v[8] % asciiConverter) * 1);  // Default er tilsvarende den første
        break;
      }
    }
  }
  return alarmTidIMs;
}

sdfs
