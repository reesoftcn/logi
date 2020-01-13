# LogI: A printf like C++ log interface
Simple, clean, easy-to-use log macros

## Latest version
1.0

## Release date
2020-01-13

## License
MIT (http://opensource.org/licenses/MIT)

## Example
```
#include <LogI/LogI10.h>

bool SaveFile(const char* sFilePath, const unsigned char* pData, int iLength)
{
	if (sFilePath == NULL || sFilePath[0] == '\0'
		|| pData == NULL
		|| iLength <= 0)
	{
		LOG_NOTIFICATION("Invalid parameters");

		return false;
	}
	else
	{
		LOG_DEBUGGING("FilePath = %s, Length = %d", sFilePath, iLength);
	}

	FILE* pFile = fopen(sFilePath, "wb");

	if (pFile == NULL)
	{
		LOG_ERROR("Failed to open file");

		return false;
	}

	LOG_INFORMATION("Open file successfully");

	bool bResult = true;

	size_t iWriteResult = fwrite(pData, iLength, 1, pFile);

	if (iWriteResult == iLength)
	{
		LOG_INFORMATION("Write file successfully");
	}
	else
	{
		LOG_ERROR("Failed to write file, result = %u", iWriteResult);

		bResult = false;
	}

	fclose(pFile);
	pFile = NULL;

	return bResult;
}
```
