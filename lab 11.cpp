#include <stdio.h>
#include <stdlib.h> // for exit()
int main() {
 int b[20], l[20], n, i, pa, offset, segment;
 printf("\nProgram for Segmentation\n");
 printf("Enter the number of segments: ");
 scanf("%d", &n);
 printf("Enter the base address and limit for each segment:\n");
 for (i = 0; i < n; i++) {
 printf("Segment %d Base: ", i);
 scanf("%d", &b[i]);
 printf("Segment %d Limit: ", i);
 scanf("%d", &l[i]);
 }
 printf("\nEnter the segment number and offset (logicaladdress):\n");
 printf("Segment number: ");
 scanf("%d", &segment);
 printf("Offset: ");
 scanf("%d", &offset);
 if (segment < 0 || segment >= n) {
 printf("\nInvalid segment number.\n");
 return 1;
 }
 if (offset < l[segment]) {
 pa = b[segment] + offset;
 printf("\n\tSegment\tBase\tLimit\tOffset\tPhysicalAddress\n");
 printf("\t%d\t%d\t%d\t%d\t%d\n", segment, b[segment],
l[segment], offset, pa);
 } else {
 printf("\nOffset exceeds segment limit.\n");
 return 1;
 }
 return 0;
}

