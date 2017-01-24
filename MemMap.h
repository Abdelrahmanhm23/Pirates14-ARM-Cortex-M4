#ifndef MEMMAP_H_
#define MEMMAP_H_

#include <stdint.h>

#define EN0		*((volatile uint32_t *)(0xE000E000 + 0x100))

// Run time clock gate for GPIO
#define RCGCGPIO 			*((volatile uint32_t *)0x400FE608)

// PORTF definitions
#define PORTA_BASE 			0x40004000
#define PORTB_BASE 			0x40005000
#define PORTC_BASE 			0x40006000
#define PORTD_BASE 			0x40007000
#define PORTE_BASE 			0x40024000
#define PORTF_BASE 			0x40025000

#define GPIODATA_PORTA 		*((volatile uint32_t *)(PORTA_BASE + 0x3FC))
#define GPIODIR_PORTA 		*((volatile uint32_t *)(PORTA_BASE + 0x400))
#define GPIOIS_PORTA 		*((volatile uint32_t *)(PORTA_BASE + 0x404))
#define GPIOIBE_PORTA 		*((volatile uint32_t *)(PORTA_BASE + 0x408))
#define GPIOEV_PORTA 		*((volatile uint32_t *)(PORTA_BASE + 0x40C))
#define GPIOIM_PORTA 		*((volatile uint32_t *)(PORTA_BASE + 0x410))
#define GPIORIS_PORTA 		*((volatile uint32_t *)(PORTA_BASE + 0x414))
#define GPIOMIS_PORTA 		*((volatile uint32_t *)(PORTA_BASE + 0x418))
#define GPIOICR_PORTA 		*((volatile uint32_t *)(PORTA_BASE + 0x41C))
#define GPIOAFSEL_PORTA 	*((volatile uint32_t *)(PORTA_BASE + 0x420))
#define GPIODR2R_PORTA 		*((volatile uint32_t *)(PORTA_BASE + 0x500))
#define GPIODR4R_PORTA 		*((volatile uint32_t *)(PORTA_BASE + 0x504))
#define GPIODR8R_PORTA 		*((volatile uint32_t *)(PORTA_BASE + 0x508))
#define GPIOODR_PORTA 		*((volatile uint32_t *)(PORTA_BASE + 0x50C))
#define GPIOPUR_PORTA 		*((volatile uint32_t *)(PORTA_BASE + 0x510))
#define GPIOPDR_PORTA 		*((volatile uint32_t *)(PORTA_BASE + 0x514))
#define GPIOSLR_PORTA 		*((volatile uint32_t *)(PORTA_BASE + 0x518))
#define GPIODEN_PORTA 		*((volatile uint32_t *)(PORTA_BASE + 0x51C))
#define GPIOLOCK_PORTA 		*((volatile uint32_t *)(PORTA_BASE + 0x520))
#define GPIOCR_PORTA 		*((volatile uint32_t *)(PORTA_BASE + 0x524))
#define GPIOAMSEL_PORTA 	*((volatile uint32_t *)(PORTA_BASE + 0x528))
#define GPIOPCTL_PORTA 		*((volatile uint32_t *)(PORTA_BASE + 0x52C))
#define GPIOADCCTL_PORTA	*((volatile uint32_t *)(PORTA_BASE + 0x530))
#define GPIODMACTL_PORTA	*((volatile uint32_t *)(PORTA_BASE + 0x534))
#define GPIOPeriphID4_PORTA *((volatile uint32_t *)(PORTA_BASE + 0xFD0))
#define GPIOPeriphID5_PORTA *((volatile uint32_t *)(PORTA_BASE + 0xFD4))
#define GPIOPeriphID6_PORTA *((volatile uint32_t *)(PORTA_BASE + 0xFD8))
#define GPIOPeriphID7_PORTA *((volatile uint32_t *)(PORTA_BASE + 0xFDC))
#define GPIOPeriphID0_PORTA *((volatile uint32_t *)(PORTA_BASE + 0xFE0))
#define GPIOPeriphID1_PORTA *((volatile uint32_t *)(PORTA_BASE + 0xFE4))
#define GPIOPeriphID2_PORTA *((volatile uint32_t *)(PORTA_BASE + 0xFE8))
#define GPIOPeriphID3_PORTA *((volatile uint32_t *)(PORTA_BASE + 0xFEC))
#define GPIOPCellID0_PORTA 	*((volatile uint32_t *)(PORTA_BASE + 0xFF0))
#define GPIOPCellID1_PORTA 	*((volatile uint32_t *)(PORTA_BASE + 0xFF4))
#define GPIOPCellID2_PORTA 	*((volatile uint32_t *)(PORTA_BASE + 0xFF8))
#define GPIOPCellID3_PORTA 	*((volatile uint32_t *)(PORTA_BASE + 0xFFC))
#define WRITE_GPIODATA_PORTA(MASK,VALUE) 	*( (volatile uint32_t *) ( (MASK<<2) +PORTA_BASE) ) = VALUE
#define READ_GPIODATA_PORTA(MASK) 			*( (volatile uint32_t *) ( (MASK<<2) +PORTA_BASE) )
#define GPIODATA_VAL_PORTA(MASK,DATA) *((volatile uint32_t*)((MASK << 2) + PORTA_BASE)) = DATA
#define GPIODATA_PORTA_READ(MASK)  *((volatile uint32_t*)(PORTA_BASE + 0x000 + (MASK <<2)))


#define GPIODATA_PORTB 		*((volatile uint32_t *)(PORTB_BASE + 0x3FC))
#define GPIODIR_PORTB 		*((volatile uint32_t *)(PORTB_BASE + 0x400))
#define GPIOIS_PORTB 		*((volatile uint32_t *)(PORTB_BASE + 0x404))
#define GPIOIBE_PORTB 		*((volatile uint32_t *)(PORTB_BASE + 0x408))
#define GPIOEV_PORTB 		*((volatile uint32_t *)(PORTB_BASE + 0x40C))
#define GPIOIM_PORTB 		*((volatile uint32_t *)(PORTB_BASE + 0x410))
#define GPIORIS_PORTB 		*((volatile uint32_t *)(PORTB_BASE + 0x414))
#define GPIOMIS_PORTB 		*((volatile uint32_t *)(PORTB_BASE + 0x418))
#define GPIOICR_PORTB 		*((volatile uint32_t *)(PORTB_BASE + 0x41C))
#define GPIOAFSEL_PORTB 	*((volatile uint32_t *)(PORTB_BASE + 0x420))
#define GPIODR2R_PORTB 		*((volatile uint32_t *)(PORTB_BASE + 0x500))
#define GPIODR4R_PORTB 		*((volatile uint32_t *)(PORTB_BASE + 0x504))
#define GPIODR8R_PORTB 		*((volatile uint32_t *)(PORTB_BASE + 0x508))
#define GPIOODR_PORTB 		*((volatile uint32_t *)(PORTB_BASE + 0x50C))
#define GPIOPUR_PORTB 		*((volatile uint32_t *)(PORTB_BASE + 0x510))
#define GPIOPDR_PORTB 		*((volatile uint32_t *)(PORTB_BASE + 0x514))
#define GPIOSLR_PORTB 		*((volatile uint32_t *)(PORTB_BASE + 0x518))
#define GPIODEN_PORTB 		*((volatile uint32_t *)(PORTB_BASE + 0x51C))
#define GPIOLOCK_PORTB 		*((volatile uint32_t *)(PORTB_BASE + 0x520))
#define GPIOCR_PORTB 		*((volatile uint32_t *)(PORTB_BASE + 0x524))
#define GPIOAMSEL_PORTB 	*((volatile uint32_t *)(PORTB_BASE + 0x528))
#define GPIOPCTL_PORTB 		*((volatile uint32_t *)(PORTB_BASE + 0x52C))
#define GPIOADCCTL_PORTB	*((volatile uint32_t *)(PORTB_BASE + 0x530))
#define GPIODMACTL_PORTB	*((volatile uint32_t *)(PORTB_BASE + 0x534))
#define GPIOPeriphID4_PORTB *((volatile uint32_t *)(PORTB_BASE + 0xFD0))
#define GPIOPeriphID5_PORTB *((volatile uint32_t *)(PORTB_BASE + 0xFD4))
#define GPIOPeriphID6_PORTB *((volatile uint32_t *)(PORTB_BASE + 0xFD8))
#define GPIOPeriphID7_PORTB *((volatile uint32_t *)(PORTB_BASE + 0xFDC))
#define GPIOPeriphID0_PORTB *((volatile uint32_t *)(PORTB_BASE + 0xFE0))
#define GPIOPeriphID1_PORTB *((volatile uint32_t *)(PORTB_BASE + 0xFE4))
#define GPIOPeriphID2_PORTB *((volatile uint32_t *)(PORTB_BASE + 0xFE8))
#define GPIOPeriphID3_PORTB *((volatile uint32_t *)(PORTB_BASE + 0xFEC))
#define GPIOPCellID0_PORTB 	*((volatile uint32_t *)(PORTB_BASE + 0xFF0))
#define GPIOPCellID1_PORTB 	*((volatile uint32_t *)(PORTB_BASE + 0xFF4))
#define GPIOPCellID2_PORTB 	*((volatile uint32_t *)(PORTB_BASE + 0xFF8))
#define GPIOPCellID3_PORTB 	*((volatile uint32_t *)(PORTB_BASE + 0xFFC))
#define WRITE_GPIODATA_PORTB(MASK,VALUE) 	*( (volatile uint32_t *) ( (MASK<<2) +PORTB_BASE) ) = VALUE
#define READ_GPIODATA_PORTB(MASK) 			*( (volatile uint32_t *) ( (MASK<<2) +PORTB_BASE) )
#define GPIODATA_VAL_PORTB(MASK,DATA) *((volatile uint32_t*)((MASK << 2) + PORTB_BASE)) = DATA
#define GPIODATA_PORTB_READ(MASK)  *((volatile uint32_t*)(PORTB_BASE + 0x000 + (MASK <<2)))


#define GPIODATA_PORTC 		*((volatile uint32_t *)(PORTC_BASE + 0x3FC))
#define GPIODIR_PORTC 		*((volatile uint32_t *)(PORTC_BASE + 0x400))
#define GPIOIS_PORTC 		*((volatile uint32_t *)(PORTC_BASE + 0x404))
#define GPIOIBE_PORTC 		*((volatile uint32_t *)(PORTC_BASE + 0x408))
#define GPIOEV_PORTC 		*((volatile uint32_t *)(PORTC_BASE + 0x40C))
#define GPIOIM_PORTC 		*((volatile uint32_t *)(PORTC_BASE + 0x410))
#define GPIORIS_PORTC 		*((volatile uint32_t *)(PORTC_BASE + 0x414))
#define GPIOMIS_PORTC 		*((volatile uint32_t *)(PORTC_BASE + 0x418))
#define GPIOICR_PORTC 		*((volatile uint32_t *)(PORTC_BASE + 0x41C))
#define GPIOAFSEL_PORTC 	*((volatile uint32_t *)(PORTC_BASE + 0x420))
#define GPIODR2R_PORTC 		*((volatile uint32_t *)(PORTC_BASE + 0x500))
#define GPIODR4R_PORTC 		*((volatile uint32_t *)(PORTC_BASE + 0x504))
#define GPIODR8R_PORTC 		*((volatile uint32_t *)(PORTC_BASE + 0x508))
#define GPIOODR_PORTC 		*((volatile uint32_t *)(PORTC_BASE + 0x50C))
#define GPIOPUR_PORTC 		*((volatile uint32_t *)(PORTC_BASE + 0x510))
#define GPIOPDR_PORTC 		*((volatile uint32_t *)(PORTC_BASE + 0x514))
#define GPIOSLR_PORTC 		*((volatile uint32_t *)(PORTC_BASE + 0x518))
#define GPIODEN_PORTC 		*((volatile uint32_t *)(PORTC_BASE + 0x51C))
#define GPIOLOCK_PORTC 		*((volatile uint32_t *)(PORTC_BASE + 0x520))
#define GPIOCR_PORTC 		*((volatile uint32_t *)(PORTC_BASE + 0x524))
#define GPIOAMSEL_PORTC 	*((volatile uint32_t *)(PORTC_BASE + 0x528))
#define GPIOPCTL_PORTC 		*((volatile uint32_t *)(PORTC_BASE + 0x52C))
#define GPIOADCCTL_PORTC	*((volatile uint32_t *)(PORTC_BASE + 0x530))
#define GPIODMACTL_PORTC	*((volatile uint32_t *)(PORTC_BASE + 0x534))
#define GPIOPeriphID4_PORTC *((volatile uint32_t *)(PORTC_BASE + 0xFD0))
#define GPIOPeriphID5_PORTC *((volatile uint32_t *)(PORTC_BASE + 0xFD4))
#define GPIOPeriphID6_PORTC *((volatile uint32_t *)(PORTC_BASE + 0xFD8))
#define GPIOPeriphID7_PORTC *((volatile uint32_t *)(PORTC_BASE + 0xFDC))
#define GPIOPeriphID0_PORTC *((volatile uint32_t *)(PORTC_BASE + 0xFE0))
#define GPIOPeriphID1_PORTC *((volatile uint32_t *)(PORTC_BASE + 0xFE4))
#define GPIOPeriphID2_PORTC *((volatile uint32_t *)(PORTC_BASE + 0xFE8))
#define GPIOPeriphID3_PORTC *((volatile uint32_t *)(PORTC_BASE + 0xFEC))
#define GPIOPCellID0_PORTC 	*((volatile uint32_t *)(PORTC_BASE + 0xFF0))
#define GPIOPCellID1_PORTC 	*((volatile uint32_t *)(PORTC_BASE + 0xFF4))
#define GPIOPCellID2_PORTC 	*((volatile uint32_t *)(PORTC_BASE + 0xFF8))
#define GPIOPCellID3_PORTC 	*((volatile uint32_t *)(PORTC_BASE + 0xFFC))
#define WRITE_GPIODATA_PORTC(MASK,VALUE) 	*( (volatile uint32_t *) ( (MASK<<2) +PORTC_BASE) ) = VALUE
#define READ_GPIODATA_PORTC(MASK) 			*( (volatile uint32_t *) ( (MASK<<2) +PORTC_BASE) )
#define GPIODATA_VAL_PORTC(MASK,DATA) *((volatile uint32_t*)((MASK << 2) + PORTC_BASE)) = DATA
#define GPIODATA_PORTC_READ(MASK)  *((volatile uint32_t*)(PORTC_BASE + 0x000 + (MASK <<2)))

#define GPIODATA_PORTD 		*((volatile uint32_t *)(PORTD_BASE + 0x3FC))
#define GPIODIR_PORTD 		*((volatile uint32_t *)(PORTD_BASE + 0x400))
#define GPIOIS_PORTD 		*((volatile uint32_t *)(PORTD_BASE + 0x404))
#define GPIOIBE_PORTD 		*((volatile uint32_t *)(PORTD_BASE + 0x408))
#define GPIOEV_PORTD 		*((volatile uint32_t *)(PORTD_BASE + 0x40C))
#define GPIOIM_PORTD 		*((volatile uint32_t *)(PORTD_BASE + 0x410))
#define GPIORIS_PORTD 		*((volatile uint32_t *)(PORTD_BASE + 0x414))
#define GPIOMIS_PORTD 		*((volatile uint32_t *)(PORTD_BASE + 0x418))
#define GPIOICR_PORTD 		*((volatile uint32_t *)(PORTD_BASE + 0x41C))
#define GPIOAFSEL_PORTD 	*((volatile uint32_t *)(PORTD_BASE + 0x420))
#define GPIODR2R_PORTD 		*((volatile uint32_t *)(PORTD_BASE + 0x500))
#define GPIODR4R_PORTD 		*((volatile uint32_t *)(PORTD_BASE + 0x504))
#define GPIODR8R_PORTD 		*((volatile uint32_t *)(PORTD_BASE + 0x508))
#define GPIOODR_PORTD 		*((volatile uint32_t *)(PORTD_BASE + 0x50C))
#define GPIOPUR_PORTD 		*((volatile uint32_t *)(PORTD_BASE + 0x510))
#define GPIOPDR_PORTD 		*((volatile uint32_t *)(PORTD_BASE + 0x514))
#define GPIOSLR_PORTD 		*((volatile uint32_t *)(PORTD_BASE + 0x518))
#define GPIODEN_PORTD 		*((volatile uint32_t *)(PORTD_BASE + 0x51C))
#define GPIOLOCK_PORTD 		*((volatile uint32_t *)(PORTD_BASE + 0x520))
#define GPIOCR_PORTD 		*((volatile uint32_t *)(PORTD_BASE + 0x524))
#define GPIOAMSEL_PORTD 	*((volatile uint32_t *)(PORTD_BASE + 0x528))
#define GPIOPCTL_PORTD 		*((volatile uint32_t *)(PORTD_BASE + 0x52C))
#define GPIOADCCTL_PORTD	*((volatile uint32_t *)(PORTD_BASE + 0x530))
#define GPIODMACTL_PORTD	*((volatile uint32_t *)(PORTD_BASE + 0x534))
#define GPIOPeriphID4_PORTD *((volatile uint32_t *)(PORTD_BASE + 0xFD0))
#define GPIOPeriphID5_PORTD *((volatile uint32_t *)(PORTD_BASE + 0xFD4))
#define GPIOPeriphID6_PORTD *((volatile uint32_t *)(PORTD_BASE + 0xFD8))
#define GPIOPeriphID7_PORTD *((volatile uint32_t *)(PORTD_BASE + 0xFDC))
#define GPIOPeriphID0_PORTD *((volatile uint32_t *)(PORTD_BASE + 0xFE0))
#define GPIOPeriphID1_PORTD *((volatile uint32_t *)(PORTD_BASE + 0xFE4))
#define GPIOPeriphID2_PORTD *((volatile uint32_t *)(PORTD_BASE + 0xFE8))
#define GPIOPeriphID3_PORTD *((volatile uint32_t *)(PORTD_BASE + 0xFEC))
#define GPIOPCellID0_PORTD 	*((volatile uint32_t *)(PORTD_BASE + 0xFF0))
#define GPIOPCellID1_PORTD 	*((volatile uint32_t *)(PORTD_BASE + 0xFF4))
#define GPIOPCellID2_PORTD 	*((volatile uint32_t *)(PORTD_BASE + 0xFF8))
#define GPIOPCellID3_PORTD 	*((volatile uint32_t *)(PORTD_BASE + 0xFFC))
#define WRITE_GPIODATA_PORTD(MASK,VALUE) 	*( (volatile uint32_t *) ( (MASK<<2) +PORTD_BASE) ) = VALUE
#define READ_GPIODATA_PORTD(MASK) 			*( (volatile uint32_t *) ( (MASK<<2) +PORTD_BASE) )
#define GPIODATA_VAL_PORTD(MASK,DATA) *((volatile uint32_t*)((MASK << 2) + PORTF_BASE)) = DATA
#define GPIODATA_PORTD_READ(MASK)  *((volatile uint32_t*)(PORTF_BASE + 0x000 + (MASK <<2)))


#define GPIODATA_PORTE 		*((volatile uint32_t *)(PORTE_BASE + 0x3FC))
#define GPIODIR_PORTE 		*((volatile uint32_t *)(PORTE_BASE + 0x400))
#define GPIOIS_PORTE 		*((volatile uint32_t *)(PORTE_BASE + 0x404))
#define GPIOIBE_PORTE 		*((volatile uint32_t *)(PORTE_BASE + 0x408))
#define GPIOEV_PORTE 		*((volatile uint32_t *)(PORTE_BASE + 0x40C))
#define GPIOIM_PORTE 		*((volatile uint32_t *)(PORTE_BASE + 0x410))
#define GPIORIS_PORTE 		*((volatile uint32_t *)(PORTE_BASE + 0x414))
#define GPIOMIS_PORTE 		*((volatile uint32_t *)(PORTE_BASE + 0x418))
#define GPIOICR_PORTE 		*((volatile uint32_t *)(PORTE_BASE + 0x41C))
#define GPIOAFSEL_PORTE 	*((volatile uint32_t *)(PORTE_BASE + 0x420))
#define GPIODR2R_PORTE 		*((volatile uint32_t *)(PORTE_BASE + 0x500))
#define GPIODR4R_PORTE 		*((volatile uint32_t *)(PORTE_BASE + 0x504))
#define GPIODR8R_PORTE 		*((volatile uint32_t *)(PORTE_BASE + 0x508))
#define GPIOODR_PORTE 		*((volatile uint32_t *)(PORTE_BASE + 0x50C))
#define GPIOPUR_PORTE 		*((volatile uint32_t *)(PORTE_BASE + 0x510))
#define GPIOPDR_PORTE 		*((volatile uint32_t *)(PORTE_BASE + 0x514))
#define GPIOSLR_PORTE 		*((volatile uint32_t *)(PORTE_BASE + 0x518))
#define GPIODEN_PORTE 		*((volatile uint32_t *)(PORTE_BASE + 0x51C))
#define GPIOLOCK_PORTE 		*((volatile uint32_t *)(PORTE_BASE + 0x520))
#define GPIOCR_PORTE 		*((volatile uint32_t *)(PORTE_BASE + 0x524))
#define GPIOAMSEL_PORTE 	*((volatile uint32_t *)(PORTE_BASE + 0x528))
#define GPIOPCTL_PORTE 		*((volatile uint32_t *)(PORTE_BASE + 0x52C))
#define GPIOADCCTL_PORTE	*((volatile uint32_t *)(PORTE_BASE + 0x530))
#define GPIODMACTL_PORTE	*((volatile uint32_t *)(PORTE_BASE + 0x534))
#define GPIOPeriphID4_PORTE *((volatile uint32_t *)(PORTE_BASE + 0xFD0))
#define GPIOPeriphID5_PORTE *((volatile uint32_t *)(PORTE_BASE + 0xFD4))
#define GPIOPeriphID6_PORTE *((volatile uint32_t *)(PORTE_BASE + 0xFD8))
#define GPIOPeriphID7_PORTE *((volatile uint32_t *)(PORTE_BASE + 0xFDC))
#define GPIOPeriphID0_PORTE *((volatile uint32_t *)(PORTE_BASE + 0xFE0))
#define GPIOPeriphID1_PORTE *((volatile uint32_t *)(PORTE_BASE + 0xFE4))
#define GPIOPeriphID2_PORTE *((volatile uint32_t *)(PORTE_BASE + 0xFE8))
#define GPIOPeriphID3_PORTE *((volatile uint32_t *)(PORTE_BASE + 0xFEC))
#define GPIOPCellID0_PORTE 	*((volatile uint32_t *)(PORTE_BASE + 0xFF0))
#define GPIOPCellID1_PORTE 	*((volatile uint32_t *)(PORTE_BASE + 0xFF4))
#define GPIOPCellID2_PORTE 	*((volatile uint32_t *)(PORTE_BASE + 0xFF8))
#define GPIOPCellID3_PORTE 	*((volatile uint32_t *)(PORTE_BASE + 0xFFC))
#define WRITE_GPIODATA_PORTE(MASK,VALUE) 	*( (volatile uint32_t *) ( (MASK<<2) +PORTE_BASE) ) = VALUE
#define READ_GPIODATA_PORTE(MASK) 			*( (volatile uint32_t *) ( (MASK<<2) +PORTE_BASE) )
#define GPIODATA_VAL_PORTE(MASK,DATA) *((volatile uint32_t*)((MASK << 2) + PORTF_BASE)) = DATA
#define GPIODATA_PORTE_READ(MASK)  *((volatile uint32_t*)(PORTF_BASE + 0x000 + (MASK <<2)))

#define GPIODATA_PORTF 		*((volatile uint32_t *)(PORTF_BASE + 0x3FC))
#define GPIODIR_PORTF 		*((volatile uint32_t *)(PORTF_BASE + 0x400))
#define GPIOIS_PORTF 		*((volatile uint32_t *)(PORTF_BASE + 0x404))
#define GPIOIBE_PORTF 		*((volatile uint32_t *)(PORTF_BASE + 0x408))
#define GPIOEV_PORTF 		*((volatile uint32_t *)(PORTF_BASE + 0x40C))
#define GPIOIM_PORTF 		*((volatile uint32_t *)(PORTF_BASE + 0x410))
#define GPIORIS_PORTF 		*((volatile uint32_t *)(PORTF_BASE + 0x414))
#define GPIOMIS_PORTF 		*((volatile uint32_t *)(PORTF_BASE + 0x418))
#define GPIOICR_PORTF 		*((volatile uint32_t *)(PORTF_BASE + 0x41C))
#define GPIOAFSEL_PORTF 	*((volatile uint32_t *)(PORTF_BASE + 0x420))
#define GPIODR2R_PORTF 		*((volatile uint32_t *)(PORTF_BASE + 0x500))
#define GPIODR4R_PORTF 		*((volatile uint32_t *)(PORTF_BASE + 0x504))
#define GPIODR8R_PORTF 		*((volatile uint32_t *)(PORTF_BASE + 0x508))
#define GPIOODR_PORTF 		*((volatile uint32_t *)(PORTF_BASE + 0x50C))
#define GPIOPUR_PORTF 		*((volatile uint32_t *)(PORTF_BASE + 0x510))
#define GPIOPDR_PORTF 		*((volatile uint32_t *)(PORTF_BASE + 0x514))
#define GPIOSLR_PORTF 		*((volatile uint32_t *)(PORTF_BASE + 0x518))
#define GPIODEN_PORTF 		*((volatile uint32_t *)(PORTF_BASE + 0x51C))
#define GPIOLOCK_PORTF 		*((volatile uint32_t *)(PORTF_BASE + 0x520))
#define GPIOCR_PORTF 		*((volatile uint32_t *)(PORTF_BASE + 0x524))
#define GPIOAMSEL_PORTF 	*((volatile uint32_t *)(PORTF_BASE + 0x528))
#define GPIOPCTL_PORTF 		*((volatile uint32_t *)(PORTF_BASE + 0x52C))
#define GPIOADCCTL_PORTF	*((volatile uint32_t *)(PORTF_BASE + 0x530))
#define GPIODMACTL_PORTF	*((volatile uint32_t *)(PORTF_BASE + 0x534))
#define GPIOPeriphID4_PORTF *((volatile uint32_t *)(PORTF_BASE + 0xFD0))
#define GPIOPeriphID5_PORTF *((volatile uint32_t *)(PORTF_BASE + 0xFD4))
#define GPIOPeriphID6_PORTF *((volatile uint32_t *)(PORTF_BASE + 0xFD8))
#define GPIOPeriphID7_PORTF *((volatile uint32_t *)(PORTF_BASE + 0xFDC))
#define GPIOPeriphID0_PORTF *((volatile uint32_t *)(PORTF_BASE + 0xFE0))
#define GPIOPeriphID1_PORTF *((volatile uint32_t *)(PORTF_BASE + 0xFE4))
#define GPIOPeriphID2_PORTF *((volatile uint32_t *)(PORTF_BASE + 0xFE8))
#define GPIOPeriphID3_PORTF *((volatile uint32_t *)(PORTF_BASE + 0xFEC))
#define GPIOPCellID0_PORTF 	*((volatile uint32_t *)(PORTF_BASE + 0xFF0))
#define GPIOPCellID1_PORTF 	*((volatile uint32_t *)(PORTF_BASE + 0xFF4))
#define GPIOPCellID2_PORTF 	*((volatile uint32_t *)(PORTF_BASE + 0xFF8))
#define GPIOPCellID3_PORTF 	*((volatile uint32_t *)(PORTF_BASE + 0xFFC))
#define WRITE_GPIODATA_PORTF(MASK,VALUE) 	*( (volatile uint32_t *) ( (MASK<<2) +PORTF_BASE) ) = VALUE
#define READ_GPIODATA_PORTF(MASK) 			*( (volatile uint32_t *) ( (MASK<<2) +PORTF_BASE) )
#define GPIODATA_VAL_PORTF(MASK,DATA) *((volatile uint32_t*)((MASK << 2) + PORTF_BASE)) = DATA
#define GPIODATA_PORTF_READ(MASK)  *((volatile uint32_t*)(PORTF_BASE + 0x000 + (MASK <<2)))


// Run time clock gate for UART
#define RCGCUART *((volatile uint32_t *)(0x400fe000 + 0x618))

// UART REGISTERS BASES
#define UART0_BASE 0x4000C000
#define UART1_BASE 0x4000D000
#define UART2_BASE 0x4000E000
#define UART3_BASE 0x4000F000
#define UART4_BASE 0x40010000
#define UART5_BASE 0x40011000
#define UART6_BASE 0x40012000
#define UART7_BASE 0x40013000

///////////////////////// UART0 /////////////////////////
	// DATA REGISTER
#define UARTDR_UART0 *((volatile uint32_t *)(UART0_BASE))
	// DMA CONTROL REGISTER
#define UARTDMACTL_UART0 *((volatile uint32_t *)(UART0_BASE + 0x048))
	//CLOCK CONTROL REGISTERS
#define UARTCTL_UART0 *((volatile uint32_t *)(UART0_BASE + 0x030))
#define UARTCC_UART0 *((volatile uint32_t *)(UART0_BASE + 0xFC8))
	//BAUD RATE GENERATOR REGISTERS
#define UARTIBRD_UART0 *((volatile uint32_t *)(UART0_BASE + 0x024))
#define UARTFBRD_UART0 *((volatile uint32_t *)(UART0_BASE + 0x028))
	//CONTROL/STATUS REGISTERS
#define UARTRSRUARTECR_UART0 *((volatile uint32_t *)(UART0_BASE + 0x004))		// read only status register and write for error clear
#define UARTFR_UART0 *((volatile uint32_t *)(UART0_BASE + 0x018))
#define UARTLCRH_UART0 *((volatile uint32_t *)(UART0_BASE + 0x02C))				// configuration of parity,data,fifo enable or disable,..
#define UARTCTL_UART0 *((volatile uint32_t *)(UART0_BASE + 0x030))
#define UARTILPR_UART0 *((volatile uint32_t *)(UART0_BASE + 0x020))
#define UART9BITADDR_UART0 *((volatile uint32_t *)(UART0_BASE + 0x0A4))
#define UART9BITAMASK_UART0 *((volatile uint32_t *)(UART0_BASE + 0x0A8))
#define UARTPP_UART0 *((volatile uint32_t *)(UART0_BASE + 0xFC0))
	//INTERRUPT CONTROL REGISTERS
#define UARTIFLS_UART0 *((volatile uint32_t *)(UART0_BASE + 0x034))
#define UARTIM_UART0 *((volatile uint32_t *)(UART0_BASE + 0x038))
#define UARTRIS_UART0 *((volatile uint32_t *)(UART0_BASE + 0x03C))
#define UARTMIS_UART0 *((volatile uint32_t *)(UART0_BASE + 0x040))
#define UARTICR_UART0 *((volatile uint32_t *)(UART0_BASE + 0x044))

///////////////////////// UART1 /////////////////////////
	// DATA REGISTER
#define UARTDR_UART1 *((volatile uint32_t *)(UART1_BASE))
	// DMA CONTROL REGISTER
#define UARTDMACTL_UART1 *((volatile uint32_t *)(UART1_BASE + 0x048))
	//CLOCK CONTROL REGISTERS
#define UARTCTL_UART1 *((volatile uint32_t *)(UART1_BASE + 0x030))
#define UARTCC_UART1 *((volatile uint32_t *)(UART1_BASE + 0xFC8))
	//BAUD RATE GENERATOR REGISTERS
#define UARTIBRD_UART1 *((volatile uint32_t *)(UART1_BASE + 0x024))
#define UARTFBRD_UART1 *((volatile uint32_t *)(UART1_BASE + 0x028))
	//CONTROL/STATUS REGISTERS
#define UARTRSRUARTECR_UART1 *((volatile uint32_t *)(UART1_BASE + 0x004))		// read only status register and write for error clear
#define UARTFR_UART1 *((volatile uint32_t *)(UART1_BASE + 0x018))
#define UARTLCRH_UART1 *((volatile uint32_t *)(UART1_BASE + 0x02C))				// configuration of parity,data,fifo enable or disable,..
#define UARTCTL_UART1 *((volatile uint32_t *)(UART1_BASE + 0x030))
#define UARTILPR_UART1 *((volatile uint32_t *)(UART1_BASE + 0x020))
#define UART9BITADDR_UART1 *((volatile uint32_t *)(UART1_BASE + 0x0A4))
#define UART9BITAMASK_UART1 *((volatile uint32_t *)(UART1_BASE + 0x0A8))
#define UARTPP_UART1 *((volatile uint32_t *)(UART1_BASE + 0xFC0))
	//INTERRUPT CONTROL REGISTERS
#define UARTIFLS_UART1 *((volatile uint32_t *)(UART1_BASE + 0x034))
#define UARTIM_UART1 *((volatile uint32_t *)(UART1_BASE + 0x038))
#define UARTRIS_UART1 *((volatile uint32_t *)(UART1_BASE + 0x03C))
#define UARTMIS_UART1 *((volatile uint32_t *)(UART1_BASE + 0x040))
#define UARTICR_UART1 *((volatile uint32_t *)(UART1_BASE + 0x044))
///////////////////////// UART2 /////////////////////////
	// DATA REGISTER
#define UARTDR_UART2 *((volatile uint32_t *)(UART2_BASE))
	// DMA CONTROL REGISTER
#define UARTDMACTL_UART2 *((volatile uint32_t *)(UART2_BASE + 0x048))
	//CLOCK CONTROL REGISTERS
#define UARTCTL_UART2 *((volatile uint32_t *)(UART2_BASE + 0x030))
#define UARTCC_UART2 *((volatile uint32_t *)(UART2_BASE + 0xFC8))
	//BAUD RATE GENERATOR REGISTERS
#define UARTIBRD_UART2 *((volatile uint32_t *)(UART2_BASE + 0x024))
#define UARTFBRD_UART2 *((volatile uint32_t *)(UART2_BASE + 0x028))
	//CONTROL/STATUS REGISTERS
#define UARTRSRUARTECR_UART2 *((volatile uint32_t *)(UART2_BASE + 0x004))		// read only status register and write for error clear
#define UARTFR_UART2 *((volatile uint32_t *)(UART2_BASE + 0x018))
#define UARTLCRH_UART2 *((volatile uint32_t *)(UART2_BASE + 0x02C))				// configuration of parity,data,fifo enable or disable,..
#define UARTCTL_UART2 *((volatile uint32_t *)(UART2_BASE + 0x030))
#define UARTILPR_UART2 *((volatile uint32_t *)(UART2_BASE + 0x020))
#define UART9BITADDR_UART2 *((volatile uint32_t *)(UART2_BASE + 0x0A4))
#define UART9BITAMASK_UART2 *((volatile uint32_t *)(UART2_BASE + 0x0A8))
#define UARTPP_UART2 *((volatile uint32_t *)(UART2_BASE + 0xFC0))
	//INTERRUPT CONTROL REGISTERS
#define UARTIFLS_UART2 *((volatile uint32_t *)(UART2_BASE + 0x034))
#define UARTIM_UART2 *((volatile uint32_t *)(UART2_BASE + 0x038))
#define UARTRIS_UART2 *((volatile uint32_t *)(UART2_BASE + 0x03C))
#define UARTMIS_UART2 *((volatile uint32_t *)(UART2_BASE + 0x040))
#define UARTICR_UART2 *((volatile uint32_t *)(UART2_BASE + 0x044))
///////////////////////// UART3 /////////////////////////
	// DATA REGISTER
#define UARTDR_UART3 *((volatile uint32_t *)(UART3_BASE))
	// DMA CONTROL REGISTER
#define UARTDMACTL_UART3 *((volatile uint32_t *)(UART3_BASE + 0x048))
	//CLOCK CONTROL REGISTERS
#define UARTCTL_UART3 *((volatile uint32_t *)(UART3_BASE + 0x030))
#define UARTCC_UART3 *((volatile uint32_t *)(UART3_BASE + 0xFC8))
	//BAUD RATE GENERATOR REGISTERS
#define UARTIBRD_UART3 *((volatile uint32_t *)(UART3_BASE + 0x024))
#define UARTFBRD_UART3 *((volatile uint32_t *)(UART3_BASE + 0x028))
	//CONTROL/STATUS REGISTERS
#define UARTRSRUARTECR_UART3 *((volatile uint32_t *)(UART3_BASE + 0x004))		// read only status register and write for error clear
#define UARTFR_UART3 *((volatile uint32_t *)(UART3_BASE + 0x018))
#define UARTLCRH_UART3 *((volatile uint32_t *)(UART3_BASE + 0x02C))				// configuration of parity,data,fifo enable or disable,..
#define UARTCTL_UART3 *((volatile uint32_t *)(UART3_BASE + 0x030))
#define UARTILPR_UART3 *((volatile uint32_t *)(UART3_BASE + 0x020))
#define UART9BITADDR_UART3 *((volatile uint32_t *)(UART3_BASE + 0x0A4))
#define UART9BITAMASK_UART3 *((volatile uint32_t *)(UART3_BASE + 0x0A8))
#define UARTPP_UART3 *((volatile uint32_t *)(UART3_BASE + 0xFC0))
	//INTERRUPT CONTROL REGISTERS
#define UARTIFLS_UART3 *((volatile uint32_t *)(UART3_BASE + 0x034))
#define UARTIM_UART3 *((volatile uint32_t *)(UART3_BASE + 0x038))
#define UARTRIS_UART3 *((volatile uint32_t *)(UART3_BASE + 0x03C))
#define UARTMIS_UART3 *((volatile uint32_t *)(UART3_BASE + 0x040))
#define UARTICR_UART3 *((volatile uint32_t *)(UART3_BASE + 0x044))
///////////////////////// UART4 /////////////////////////
	// DATA REGISTER
#define UARTDR_UART4 *((volatile uint32_t *)(UART4_BASE))
	// DMA CONTROL REGISTER
#define UARTDMACTL_UART4 *((volatile uint32_t *)(UART4_BASE + 0x048))
	//CLOCK CONTROL REGISTERS
#define UARTCTL_UART4 *((volatile uint32_t *)(UART4_BASE + 0x030))
#define UARTCC_UART4 *((volatile uint32_t *)(UART4_BASE + 0xFC8))
	//BAUD RATE GENERATOR REGISTERS
#define UARTIBRD_UART4 *((volatile uint32_t *)(UART4_BASE + 0x024))
#define UARTFBRD_UART4 *((volatile uint32_t *)(UART4_BASE + 0x028))
	//CONTROL/STATUS REGISTERS
#define UARTRSRUARTECR_UART4 *((volatile uint32_t *)(UART4_BASE + 0x004))		// read only status register and write for error clear
#define UARTFR_UART4 *((volatile uint32_t *)(UART4_BASE + 0x018))
#define UARTLCRH_UART4 *((volatile uint32_t *)(UART4_BASE + 0x02C))				// configuration of parity,data,fifo enable or disable,..
#define UARTCTL_UART4 *((volatile uint32_t *)(UART4_BASE + 0x030))
#define UARTILPR_UART4 *((volatile uint32_t *)(UART4_BASE + 0x020))
#define UART9BITADDR_UART4 *((volatile uint32_t *)(UART4_BASE + 0x0A4))
#define UART9BITAMASK_UART4 *((volatile uint32_t *)(UART4_BASE + 0x0A8))
#define UARTPP_UART4 *((volatile uint32_t *)(UART4_BASE + 0xFC0))
	//INTERRUPT CONTROL REGISTERS
#define UARTIFLS_UART4 *((volatile uint32_t *)(UART4_BASE + 0x034))
#define UARTIM_UART4 *((volatile uint32_t *)(UART4_BASE + 0x038))
#define UARTRIS_UART4 *((volatile uint32_t *)(UART4_BASE + 0x03C))
#define UARTMIS_UART4 *((volatile uint32_t *)(UART4_BASE + 0x040))
#define UARTICR_UART4 *((volatile uint32_t *)(UART4_BASE + 0x044))
///////////////////////// UART5 /////////////////////////
	// DATA REGISTER
#define UARTDR_UART5 *((volatile uint32_t *)(UART5_BASE))
	// DMA CONTROL REGISTER
#define UARTDMACTL_UART5 *((volatile uint32_t *)(UART5_BASE + 0x048))
	//CLOCK CONTROL REGISTERS
#define UARTCTL_UART5 *((volatile uint32_t *)(UART5_BASE + 0x030))
#define UARTCC_UART5 *((volatile uint32_t *)(UART5_BASE + 0xFC8))
	//BAUD RATE GENERATOR REGISTERS
#define UARTIBRD_UART5 *((volatile uint32_t *)(UART5_BASE + 0x024))
#define UARTFBRD_UART5 *((volatile uint32_t *)(UART5_BASE + 0x028))
	//CONTROL/STATUS REGISTERS
#define UARTRSRUARTECR_UART5 *((volatile uint32_t *)(UART5_BASE + 0x004))		// read only status register and write for error clear
#define UARTFR_UART5 *((volatile uint32_t *)(UART5_BASE + 0x018))
#define UARTLCRH_UART5 *((volatile uint32_t *)(UART5_BASE + 0x02C))				// configuration of parity,data,fifo enable or disable,..
#define UARTCTL_UART5 *((volatile uint32_t *)(UART5_BASE + 0x030))
#define UARTILPR_UART5 *((volatile uint32_t *)(UART5_BASE + 0x020))
#define UART9BITADDR_UART5 *((volatile uint32_t *)(UART5_BASE + 0x0A4))
#define UART9BITAMASK_UART5 *((volatile uint32_t *)(UART5_BASE + 0x0A8))
#define UARTPP_UART5 *((volatile uint32_t *)(UART5_BASE + 0xFC0))
	//INTERRUPT CONTROL REGISTERS
#define UARTIFLS_UART5 *((volatile uint32_t *)(UART5_BASE + 0x034))
#define UARTIM_UART5 *((volatile uint32_t *)(UART5_BASE + 0x038))
#define UARTRIS_UART5 *((volatile uint32_t *)(UART5_BASE + 0x03C))
#define UARTMIS_UART5 *((volatile uint32_t *)(UART5_BASE + 0x040))
#define UARTICR_UART5 *((volatile uint32_t *)(UART5_BASE + 0x044))
///////////////////////// UART6 /////////////////////////
	// DATA REGISTER
#define UARTDR_UART6 *((volatile uint32_t *)(UART6_BASE))
	// DMA CONTROL REGISTER
#define UARTDMACTL_UART6 *((volatile uint32_t *)(UART6_BASE + 0x048))
	//CLOCK CONTROL REGISTERS
#define UARTCTL_UART6 *((volatile uint32_t *)(UART6_BASE + 0x030))
#define UARTCC_UART6 *((volatile uint32_t *)(UART6_BASE + 0xFC8))
	//BAUD RATE GENERATOR REGISTERS
#define UARTIBRD_UART6 *((volatile uint32_t *)(UART6_BASE + 0x024))
#define UARTFBRD_UART6 *((volatile uint32_t *)(UART6_BASE + 0x028))
	//CONTROL/STATUS REGISTERS
#define UARTRSRUARTECR_UART6 *((volatile uint32_t *)(UART6_BASE + 0x004))		// read only status register and write for error clear
#define UARTFR_UART6 *((volatile uint32_t *)(UART6_BASE + 0x018))
#define UARTLCRH_UART6 *((volatile uint32_t *)(UART6_BASE + 0x02C))				// configuration of parity,data,fifo enable or disable,..
#define UARTCTL_UART6 *((volatile uint32_t *)(UART6_BASE + 0x030))
#define UARTILPR_UART6 *((volatile uint32_t *)(UART6_BASE + 0x020))
#define UART9BITADDR_UART6 *((volatile uint32_t *)(UART6_BASE + 0x0A4))
#define UART9BITAMASK_UART6 *((volatile uint32_t *)(UART6_BASE + 0x0A8))
#define UARTPP_UART6 *((volatile uint32_t *)(UART6_BASE + 0xFC0))
	//INTERRUPT CONTROL REGISTERS
#define UARTIFLS_UART6 *((volatile uint32_t *)(UART6_BASE + 0x034))
#define UARTIM_UART6 *((volatile uint32_t *)(UART6_BASE + 0x038))
#define UARTRIS_UART6 *((volatile uint32_t *)(UART6_BASE + 0x03C))
#define UARTMIS_UART6 *((volatile uint32_t *)(UART6_BASE + 0x040))
#define UARTICR_UART6 *((volatile uint32_t *)(UART6_BASE + 0x044))
///////////////////////// UART7 /////////////////////////
	// DATA REGISTER
#define UARTDR_UART7 *((volatile uint32_t *)(UART0_BASE))
	// DMA CONTROL REGISTER
#define UARTDMACTL_UART7 *((volatile uint32_t *)(UART7_BASE + 0x048))
	//CLOCK CONTROL REGISTERS
#define UARTCTL_UART7 *((volatile uint32_t *)(UART7_BASE + 0x030))
#define UARTCC_UART7 *((volatile uint32_t *)(UART7_BASE + 0xFC8))
	//BAUD RATE GENERATOR REGISTERS
#define UARTIBRD_UART7 *((volatile uint32_t *)(UART7_BASE + 0x024))
#define UARTFBRD_UART7 *((volatile uint32_t *)(UART7_BASE + 0x028))
	//CONTROL/STATUS REGISTERS
#define UARTRSRUARTECR_UART7 *((volatile uint32_t *)(UART7_BASE + 0x004))		// read only status register and write for error clear
#define UARTFR_UART7 *((volatile uint32_t *)(UART7_BASE + 0x018))
#define UARTLCRH_UART7 *((volatile uint32_t *)(UART7_BASE + 0x02C))				// configuration of parity,data,fifo enable or disable,..
#define UARTCTL_UART7 *((volatile uint32_t *)(UART7_BASE + 0x030))
#define UARTILPR_UART7 *((volatile uint32_t *)(UART7_BASE + 0x020))
#define UART9BITADDR_UART7 *((volatile uint32_t *)(UART7_BASE + 0x0A4))
#define UART9BITAMASK_UART7 *((volatile uint32_t *)(UART7_BASE + 0x0A8))
#define UARTPP_UART7 *((volatile uint32_t *)(UART7_BASE + 0xFC0))
	//INTERRUPT CONTROL REGISTERS
#define UARTIFLS_UART7 *((volatile uint32_t *)(UART7_BASE + 0x034))
#define UARTIM_UART7 *((volatile uint32_t *)(UART7_BASE + 0x038))
#define UARTRIS_UART7 *((volatile uint32_t *)(UART7_BASE + 0x03C))
#define UARTMIS_UART7 *((volatile uint32_t *)(UART7_BASE + 0x040))
#define UARTICR_UART7 *((volatile uint32_t *)(UART7_BASE + 0x044))


// Run time clock gate for I2C
#define RCGCI2C *((volatile uint32_t *)(0x400FE000 + 0x620))

// I2C REGISTERS BASES
#define I2C0_BASE 0x40020000
#define I2C1_BASE 0x40021000
#define I2C2_BASE 0x40022000
#define I2C3_BASE 0x40023000


///////////////////////// I2C0 /////////////////////////
	// master registers
#define I2CMSA_I2C0 *((volatile uint32_t *)(I2C0_BASE + 0x000))
#define I2CMCS_I2C0 *((volatile uint32_t *)(I2C0_BASE + 0x004))
#define I2CMDR_I2C0 *((volatile uint32_t *)(I2C0_BASE + 0x008))
#define I2CMTPR_I2C0 *((volatile uint32_t *)(I2C0_BASE + 0x00C))
#define I2CMIMR_I2C0 *((volatile uint32_t *)(I2C0_BASE + 0x010))
#define I2CMRIS_I2C0 *((volatile uint32_t *)(I2C0_BASE + 0x014))
#define I2CMMIS_I2C0 *((volatile uint32_t *)(I2C0_BASE + 0x018))
#define I2CMICR_I2C0 *((volatile uint32_t *)(I2C0_BASE + 0x01C))
#define I2CMCR_I2C0 *((volatile uint32_t *)(I2C0_BASE + 0x020))
#define I2CMCLKOCNT_I2C0 *((volatile uint32_t *)(I2C0_BASE + 0x024))
#define I2CMBMON_I2C0 *((volatile uint32_t *)(I2C0_BASE + 0x02C))
#define I2CMCR2_I2C0 *((volatile uint32_t *)(I2C0_BASE + 0x038))
	//slave registers
#define I2CSOAR_I2C0 *((volatile uint32_t *)(I2C0_BASE + 0x800))
#define I2CSCSR_I2C0 *((volatile uint32_t *)(I2C0_BASE + 0x804))
#define I2CSDR_I2C0 *((volatile uint32_t *)(I2C0_BASE + 0x804))
#define I2CSIMR_I2C0 *((volatile uint32_t *)(I2C0_BASE + 0x80C))
#define I2CSRIS_I2C0 *((volatile uint32_t *)(I2C0_BASE + 0x810))
#define I2CSMIS_I2C0 *((volatile uint32_t *)(I2C0_BASE + 0x814))
#define I2CSICR_I2C0 *((volatile uint32_t *)(I2C0_BASE + 0x818))
#define I2CSOAR2_I2C0 *((volatile uint32_t *)(I2C0_BASE + 0x81C))
#define I2CSACKCTL_I2C0 *((volatile uint32_t *)(I2C0_BASE + 0x820))


///////////////////////// I2C1 /////////////////////////
	// master registers
#define I2CMSA_I2C1 *((volatile uint32_t *)(I2C1_BASE + 0x000))
#define I2CMCS_I2C1 *((volatile uint32_t *)(I2C1_BASE + 0x004))
#define I2CMDR_I2C1 *((volatile uint32_t *)(I2C1_BASE + 0x008))
#define I2CMTPR_I2C1 *((volatile uint32_t *)(I2C1_BASE + 0x00C))
#define I2CMIMR_I2C1 *((volatile uint32_t *)(I2C1_BASE + 0x010))
#define I2CMRIS_I2C1 *((volatile uint32_t *)(I2C1_BASE + 0x014))
#define I2CMMIS_I2C1 *((volatile uint32_t *)(I2C1_BASE + 0x018))
#define I2CMICR_I2C1 *((volatile uint32_t *)(I2C1_BASE + 0x01C))
#define I2CMCR_I2C1 *((volatile uint32_t *)(I2C1_BASE + 0x020))
#define I2CMCLKOCNT_I2C1 *((volatile uint32_t *)(I2C1_BASE + 0x024))
#define I2CMBMON_I2C1 *((volatile uint32_t *)(I2C1_BASE + 0x02C))
#define I2CMCR2_I2C1 *((volatile uint32_t *)(I2C1_BASE + 0x038))
	//slave registers
#define I2CSOAR_I2C1 *((volatile uint32_t *)(I2C1_BASE + 0x800))
#define I2CSCSR_I2C1 *((volatile uint32_t *)(I2C1_BASE + 0x804))
#define I2CSDR_I2C1 *((volatile uint32_t *)(I2C1_BASE + 0x804))
#define I2CSIMR_I2C1 *((volatile uint32_t *)(I2C1_BASE + 0x80C))
#define I2CSRIS_I2C1 *((volatile uint32_t *)(I2C1_BASE + 0x810))
#define I2CSMIS_I2C1 *((volatile uint32_t *)(I2C1_BASE + 0x814))
#define I2CSICR_I2C1 *((volatile uint32_t *)(I2C1_BASE + 0x818))
#define I2CSOAR2_I2C1 *((volatile uint32_t *)(I2C1_BASE + 0x81C))
#define I2CSACKCTL_I2C1 *((volatile uint32_t *)(I2C1_BASE + 0x820))



///////////////////////// I2C2 /////////////////////////
	// master registers
#define I2CMSA_I2C2 *((volatile uint32_t *)(I2C2_BASE + 0x000))
#define I2CMCS_I2C2 *((volatile uint32_t *)(I2C2_BASE + 0x004))
#define I2CMDR_I2C2 *((volatile uint32_t *)(I2C2_BASE + 0x008))
#define I2CMTPR_I2C2 *((volatile uint32_t *)(I2C2_BASE + 0x00C))
#define I2CMIMR_I2C2 *((volatile uint32_t *)(I2C2_BASE + 0x010))
#define I2CMRIS_I2C2 *((volatile uint32_t *)(I2C2_BASE + 0x014))
#define I2CMMIS_I2C2 *((volatile uint32_t *)(I2C2_BASE + 0x018))
#define I2CMICR_I2C2 *((volatile uint32_t *)(I2C2_BASE + 0x01C))
#define I2CMCR_I2C2 *((volatile uint32_t *)(I2C2_BASE + 0x020))
#define I2CMCLKOCNT_I2C2 *((volatile uint32_t *)(I2C2_BASE + 0x024))
#define I2CMBMON_I2C2 *((volatile uint32_t *)(I2C2_BASE + 0x02C))
#define I2CMCR2_I2C2 *((volatile uint32_t *)(I2C2_BASE + 0x038))
	//slave registers
#define I2CSOAR_I2C2 *((volatile uint32_t *)(I2C2_BASE + 0x800))
#define I2CSCSR_I2C2 *((volatile uint32_t *)(I2C2_BASE + 0x804))
#define I2CSDR_I2C2 *((volatile uint32_t *)(I2C2_BASE + 0x804))
#define I2CSIMR_I2C2 *((volatile uint32_t *)(I2C2_BASE + 0x80C))
#define I2CSRIS_I2C2 *((volatile uint32_t *)(I2C2_BASE + 0x810))
#define I2CSMIS_I2C2 *((volatile uint32_t *)(I2C2_BASE + 0x814))
#define I2CSICR_I2C2 *((volatile uint32_t *)(I2C1_BASE + 0x818))
#define I2CSOAR2_I2C2 *((volatile uint32_t *)(I2C2_BASE + 0x81C))
#define I2CSACKCTL_I2C2 *((volatile uint32_t *)(I2C2_BASE + 0x820))



///////////////////////// I2C3 /////////////////////////
	// master registers
#define I2CMSA_I2C3 *((volatile uint32_t *)(I2C3_BASE + 0x000))
#define I2CMCS_I2C3 *((volatile uint32_t *)(I2C3_BASE + 0x004))
#define I2CMDR_I2C3 *((volatile uint32_t *)(I2C3_BASE + 0x008))
#define I2CMTPR_I2C3 *((volatile uint32_t *)(I2C3_BASE + 0x00C))
#define I2CMIMR_I2C3 *((volatile uint32_t *)(I2C3_BASE + 0x010))
#define I2CMRIS_I2C3 *((volatile uint32_t *)(I2C3_BASE + 0x014))
#define I2CMMIS_I2C3 *((volatile uint32_t *)(I2C3_BASE + 0x018))
#define I2CMICR_I2C3 *((volatile uint32_t *)(I2C3_BASE + 0x01C))
#define I2CMCR_I2C3 *((volatile uint32_t *)(I2C3_BASE + 0x020))
#define I2CMCLKOCNT_I2C3 *((volatile uint32_t *)(I2C3_BASE + 0x024))
#define I2CMBMON_I2C3 *((volatile uint32_t *)(I2C3_BASE + 0x02C))
#define I2CMCR2_I2C3 *((volatile uint32_t *)(I2C3_BASE + 0x038))
	//slave registers
#define I2CSOAR_I2C3 *((volatile uint32_t *)(I2C3_BASE + 0x800))
#define I2CSCSR_I2C3 *((volatile uint32_t *)(I2C3_BASE + 0x804))
#define I2CSDR_I2C3 *((volatile uint32_t *)(I2C3_BASE + 0x804))
#define I2CSIMR_I2C3 *((volatile uint32_t *)(I2C3_BASE + 0x80C))
#define I2CSRIS_I2C3 *((volatile uint32_t *)(I2C3_BASE + 0x810))
#define I2CSMIS_I2C3 *((volatile uint32_t *)(I2C3_BASE + 0x814))
#define I2CSICR_I2C3 *((volatile uint32_t *)(I2C3_BASE + 0x818))
#define I2CSOAR2_I2C3 *((volatile uint32_t *)(I2C3_BASE + 0x81C))
#define I2CSACKCTL_I2C3 *((volatile uint32_t *)(I2C3_BASE + 0x820))


/////////SPI///////
#define RCGCSSI *((volatile uint32_t *)(0x400FE000 + 0x61C))  // SPI Clock register

#define SPI0_BASE 0x40008000
#define SPI1_BASE 0x40009000
#define SPI2_BASE 0x4000A000
#define SPI3_BASE 0x4000B000

#define SPI0_SSICR0   *((volatile uint32_t *)(SPI0_BASE + 0x00))
#define SPI0_SSICR1   *((volatile uint32_t *)(SPI0_BASE + 0x004))
#define SPI0_SSIDR   *((volatile uint32_t *)(SPI0_BASE + 0x008))
#define SPI0_SSISR   *((volatile uint32_t *)(SPI0_BASE + 0x00C))
#define SPI0_SSICPSR   *((volatile uint32_t *)(SPI0_BASE + 0x010))
#define SPI0_SSIIM   *((volatile uint32_t *)(SPI0_BASE + 0x014))
#define SPI0_SSIRIS   *((volatile uint32_t *)(SPI0_BASE + 0x018))
#define SPI0_SSIMIS   *((volatile uint32_t *)(SPI0_BASE + 0x01C))
#define SPI0_SSIICR   *((volatile uint32_t *)(SPI0_BASE + 0x020))
#define SPI0_SSICC   *((volatile uint32_t *)(SPI0_BASE + 0xFC8))


#define SPI1_SSICR0   *((volatile uint32_t *)(SPI1_BASE + 0x00))
#define SPI1_SSICR1   *((volatile uint32_t *)(SPI1_BASE + 0x004))
#define SPI1_SSIDR   *((volatile uint32_t *)(SPI1_BASE + 0x008))
#define SPI1_SSISR   *((volatile uint32_t *)(SPI1_BASE + 0x00C))
#define SPI1_SSICPSR   *((volatile uint32_t *)(SPI1_BASE + 0x010))
#define SPI1_SSIIM   *((volatile uint32_t *)(SPI1_BASE + 0x014))
#define SPI1_SSIRIS   *((volatile uint32_t *)(SPI1_BASE + 0x018))
#define SPI1_SSIMIS   *((volatile uint32_t *)(SPI1_BASE + 0x01C))
#define SPI1_SSIICR   *((volatile uint32_t *)(SPI1_BASE + 0x020))
#define SPI1_SSICC   *((volatile uint32_t *)(SPI1_BASE + 0xFC8))









#define Timer0_BASE 0x40030000

#define RCGCTIMER  *((volatile uint32_t *)(0x400FE000 + 0x604))

#define GPTMCTL   *((volatile uint32_t *)(0x40030000 + 0x00C))

#define GPTMCFG  *((volatile uint32_t *)(Timer0_BASE + 0x000))
#define GPTMTAMR  *((volatile uint32_t *)(Timer0_BASE + 0x004))
#define GPTMIMR  *((volatile uint32_t *)(Timer0_BASE + 0x018))
#define GPTMICR  *((volatile uint32_t *)(Timer0_BASE + 0x024))
#define GPTMTAILR  *((volatile uint32_t *)(Timer0_BASE + 0x028))
#define GPTMTAPR  *((volatile uint32_t *)(Timer0_BASE + 0x038))

#define EN0		*((volatile uint32_t *)(0xE000E000 + 0x100))




#endif /* MEMMAP_H_ */
