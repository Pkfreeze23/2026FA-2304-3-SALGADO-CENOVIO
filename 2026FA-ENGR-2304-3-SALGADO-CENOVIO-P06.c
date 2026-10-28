#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ELEMENTS 15000

// Function protoypes (Programmer-defined fuctions)
int load_data(const char *filename, double data[], int max_size);
void calculate_statistics(const double data[], int size, double *mean, double *std_dev, double *min, double *max);
void display_report(const double data[], int size, double mean, double std_dev, double min, double max);
int search_data(const double data[], int size, double target, double epsilon);

int main() {
	double data[MAX_ELEMENTS];
	int data_size = 0;
	char filename[100];
	int choice;
	
	// Statistical variables
	double mean = 0.0, std_dev = 0.0, min = 0.0, max = 0.0;
	int stats_ready = 0;
	
	printf("=== Statistical Data Analysis Program ===\n");
	
	while (1) {
		// Menu display
		printf("\n--- Menu ---\n");
		printf("1. Load Data from File\n");
		printf("2. Perform Statistical Analysis and Display Report\n");
		printf("3. Search for a Value\n");
		printf("4. Exit\n");
		printf("Enter your choice (1-4): ");
		
		if (scanf("%d", &choice) != 1) {
			printf("Invalid input. Exiting program.\n");
			break;
			
		}
		switch (choice) {
			case 1:
			    printf("Enter the filename containing data (CSV or space-delimited): ");
			    scanf("%s", filename);
			    data_size = load_data(filename, data, MAX_ELEMENTS);
			    if (data_size > 0) {
				    printf("Successfully loaded %d data points.\n", data_size);
				    // Compute statistics automatically after loading
				    calculate_statistics(data, data_size, &mean, &std_dev, &min, &max);
				    stats_ready = 1;
			} else {
				printf("Failed to load data or file is empty.\n");
				stats_ready = 0;
			}
			break;
			
			case 2:
			    if (!stats_ready) {
				    printf("Please load valid data first (Option 1).\n");
			} else {
				display_report(data, data_size, mean, std_dev, min, max);
			}
			break;
			case 3:
			    if (data_size == 0) {
				    printf("No data availabe to search. Please load a file first.\n");
			} else {
				double target;
				printf("Enter the value to search for: ");
				scanf("%lf", &target);
				
				// Using an epsilon tolerance ofr comparing floating-point numbers
				int index = search_data(data, data_size, target, 0.00001);
				if (index != -1) {
					printf("Value %.4f found at data index %d.\n", target, index);
				} else {
					printf("Value %.4f was not found in the dataset.\n", target);
				}
			}
			break;
			
			case 4:
			    printf("Exiting program. Goodbye!\n");
			    return 0;
			
			default:
			    printf("Invalid choice. Please select an option between 1 and 4.\n");
		}
	}
	
	return 0;
}

//Function to read comma-delimited or space-delimited numbers from a file
int load_data(const char *filename, double data[], int max_size) {
	FILE *file = fopen(filename, "r");
	if (file == NULL) {
		printf("Error: Could not open file '%s'.\n", filename);
		return 0;
	}
	
	int count = 0;
	// fscanf handles both spaces, newlines, and can skip commas if we formant it or if numbers are purely space/comma spllit.
	// To cleanly handle both spaces and commas, we read numbers and explicitly discard commas if encountered commas if encountered.
	while (count < max_size && fscanf(file, "%lf", &data[count]) == 1) {
		count++;
		// Check if next character is a comma and skip it
		int ch = fgetc(file);
		if (ch != ',' && ch != EOF) {
		}
	}
	
	fclose(file);
	return count;
}

// Function to calculate mean, standard devation, minimum, and maximum
void calculate_statistics(const double data[], int size, double *mean, double *std_dev, double *min, double *max) {
	if (size <= 0) return;
	
	double sum = 0.0;
	*min = data[0];
	*max = data[0];
	
	for (int i = 0; i < size; i++) {
		sum += data[i];
		if (data[i] < *min) *min = data[i];
		if (data[i] > *max) *max = data[i];
	}
	*mean = sum / size;
	
	// Calculate Standard Deviation
	double variance_sum = 0.0;
	for (int i = 0; i < size; i++) {
		variance_sum += pow(data[i] - *mean, 2);
	}
	
	// Uses sample standard deviation if size > 1, otherwise 0
	*std_dev = (size > 1) ? sqrt(variance_sum / (size - 1)) : 0.0;
}

// Function to print a clean report of the data and calculated parameters
void display_report(const double data[], int size, double mean, double std_dev, double min, double max) {
	printf("\n================ DATA ANALYSIS REPORT ================\n");
	printf("Total Elements:    %d\n", size);
	printf("Minimum Value:     %.4f\n", min);
	printf("Maximum Value:     %.4f\n", max);
	printf("Arithemtic Mean:   %.4f\n", mean);
	printf("Std. Deviation:    %.4f\n", std_dev);
	printf("-----------------------------------------------------\n");
	printf("First up to 10 elements in dataset:\n");
	for (int i = 0; i < size && i < 10; i++) {
		printf("[%d]: %.4f ", i, data[i]);
	}
	printf("\n======================================================\n");
}

//Function to search for a specific value within the dataset
int search_data(const double data[], int size, double target, double epsilon) {
	for (int i = 0; i < size; i++) {
1		if (fabs(data[i] - target) < epsilon) {
			return i; // Return the index where it was found
		}
	}
	return -1; // Value not found 
}
			
	