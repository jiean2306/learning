#include <stdio.h>

void display_table(int table[][100], int row, int column);

int edit_exit() {

	int edit = 10;

	for (int editi = 0;edit > 1 || edit < 0;editi++) {

		printf("Press 1 to edit the table;Press 0 to end the program\n");
		printf("User input: ");
		scanf("%d", &edit);

		if (edit > 1 || edit < 0) {
			printf("Invalid input, Try again\n");
		}
	}

	return edit;
}

void edit_table(int table[][100], int row, int column) {

	int edit_row,edit_col,new_value;
	int continue_edit =1;

	while (continue_edit ==1) {
		printf("\n===EDIT MODE===\n");

		//get coordinate to edit
		printf("Enter the row to edit (1-%d): ",row);
		scanf("%d", &edit_row);
		printf("Enter the column to edit (1-%d): ", column);
		scanf("%d", &edit_col);

		//validate coordinate
		if (edit_row < 1 || edit_row > row || edit_col < 1 || edit_col > column) {
			printf("Invalid coordinate! Try again!\n");
			continue;

		}

		//show current value
		printf("Current value at [%d][%d] is %d\n",edit_row,edit_col,table[edit_row-1][edit_col-1]);
		int temp_value = table[edit_row-1][edit_col-1];
		//get and upate new value
		printf("Enter the new value: ");
		scanf("%d", &new_value);
		table[edit_row-1][edit_col-1] = new_value;
		printf("Value Updated!\n[%d][%d]: %d --> %d",edit_row,edit_col,temp_value,new_value);

		printf("\nUpdated Table\n");
		display_table(table, row, column);

		//ask if continue
		printf("Continue editing?\n <1 = Yes>\t<0 = No): ");
		scanf("%d", &continue_edit);

		if (continue_edit != 0 && continue_edit != 1) {
			printf("Invalid input. Exiting edit mode.\n");
			break;
		}
	}

	printf("Exiting edit mode\n");
}

void display_table(int table[][100], int row, int column) {

	printf("\nUSER TABLE\n");
	for (int z = 0;z<column;z++) {
		printf("========");
	}
	printf("\n");

	for (int i = 0;i<row;i++) {
		for (int j = 0;j<column;j++) {
			printf("[%6d]",table[i][j]);
		}
		printf("\n");
	}
	for (int z = 0;z<column;z++) {
		printf("========");

	}
	printf("\n");	


}


int main() {
	int row,column = 0; 
	printf("\n===USER TABLE===\n");
	printf("Enter the number of row of the table: ");
	scanf("%d", &row);
	printf("Enter the number of column of the table: ");
	scanf("%d", &column);
	
	//generate table
	int table[100][100];

	printf("Enter the number for each coordinates:\n");
	for (int i = 0;i<row;i++) {
		for (int j = 0;j<column;j++) {
			printf("[%d][%d]: ",i+1,j+1);
			scanf("%d",&table[i][j]);

		}
	}
	//display table
	display_table(table, row, column);

	//user choice on edit or exit
	int user_choice = edit_exit();

	if (user_choice == 1) {
		printf("Enter edit session\n");
		edit_table(table, row, column);

		printf("\nFinal table\n");
		display_table(table, row, column);
	}

	if (user_choice == 0) {
		printf("Program ended");
	}

	return 0;
}
