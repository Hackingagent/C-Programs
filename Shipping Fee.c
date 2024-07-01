#include <stdio.h>
#include <stdlib.h>

int within_cameroon(int Total_amount){
	int shipping_fee;
	if (Total_amount <= 25000){
		shipping_fee = 1000;
	}
	else if(Total_amount >= 26000 && Total_amount <= 50000){
		shipping_fee = 1500;
	}
	else if(Total_amount >= 51000 && Total_amount <= 75000){
		shipping_fee = 3500;
	}
	else if(Total_amount >= 76000){
		shipping_fee = 0;
	}
	return shipping_fee;
	
}
int abroad(int Total_amount){
		int shipping_fee;
	if (Total_amount <= 25000){
		shipping_fee = 2000;
	}
	else if(Total_amount >= 26000 && Total_amount <= 50000){
		shipping_fee = 2500;
	}
	else if(Total_amount >= 51000 && Total_amount <= 75000){
		shipping_fee = 5000;
	}
	else if(Total_amount >= 76000){
		shipping_fee = 0;
	}
	return shipping_fee;
}

int main() {
int choice, Amount_paid;

printf("Enter the Total Amount Paid: ");
scanf("%d", &Amount_paid);

printf("\n1. Within Cameroon.");
printf("\n2. From Abroad.");
printf("\nSelect Where Your Shpping From type '1' for within Cameroon or '2' from Abroad: ");
scanf("%d", &choice);

if(choice == 1){
	printf("Your Shipping Fee = %d CFA Francs", within_cameroon(Amount_paid));
}
else if (choice == 2){
	printf("Your Shipping Fee = %d CFA Francs", abroad(Amount_paid));
}

	return 0;
}
