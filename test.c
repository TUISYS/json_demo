
#include "tui.h"
#include "tjson.h"

void tui_json_read_test(void)
{

	char json_str1[256] = { 0 };
	tJSON *root_json, *name_json, *size_json, *array_json, *temp_json;
	int js_num = 0, i, ret;
	FILE *f;

	f = fopen("test.json", "rb");
	if (NULL == f)
		return;

	fseek(f, 0, SEEK_END);
	int len = ftell(f);
	fseek(f, 0, SEEK_SET);
	fread(json_str1, len, 1, f);
	fclose(f);

	root_json = tJSON_Parse(json_str1);
	if (NULL == root_json)
		return;

	name_json = tJSON_GetObjectItem(root_json, "name");
	if (name_json == NULL) {
		printf("get name fail\n");
		return;
	} else {
		printf("name = %s\n", name_json->valuestring);
	}

	size_json = tJSON_GetObjectItem(root_json, "size");
	if (size_json == NULL) {
		printf("get size fail\n");
		return;
	} else {
		printf("size = %d\n", size_json->valueint);
	}

	array_json = tJSON_GetObjectItem(root_json, "array");
	if (array_json == NULL) {
		printf("get array fail\n");
		return;
	} else {
		js_num = tJSON_GetArraySize(array_json);
		for (i = 0; i < js_num; i++) {
			temp_json = tJSON_GetArrayItem(array_json, i);
			if (temp_json)
				printf("%d ", temp_json->valueint);
		}
		printf("\n");
	}

	tJSON_Delete(name_json);
}

void tui_json_write_test(void)
{
	char  *str;
	tJSON *item1 = tJSON_CreateObject();
	tJSON *item15 = tJSON_CreateObject();
	tJSON *item14 = tJSON_CreateArray();

	//item15
	tJSON_AddItemToObject(item15, "item151", tJSON_CreateString("obj"));
	tJSON_AddItemToObject(item15, "item152", tJSON_CreateNumber(30));

	//item14
	tJSON_AddItemToArray(item14, tJSON_CreateString("array"));
	tJSON_AddItemToArray(item14, tJSON_CreateNumber(20));
	tJSON_AddItemToArray(item14, tJSON_CreateNull());
	tJSON_AddItemToArray(item14, tJSON_Duplicate(item15, 1));

	//item1
	tJSON_AddItemToObject(item1, "item11", tJSON_CreateString("hello"));
	tJSON_AddItemToObject(item1, "item12", tJSON_CreateNumber(10));
	tJSON_AddItemToObject(item1, "item13", tJSON_CreateFalse());
	tJSON_AddItemToObject(item1, "item14", item14);
	tJSON_AddItemToObject(item1, "item15", item15);

	str = tJSON_Print(item1);
	printf("%s\n", str);
	free(str);

	str = tJSON_PrintUnformatted(item1);
	printf("%s\n\n", str);
	free(str);

	tJSON_Delete(item1);
}
