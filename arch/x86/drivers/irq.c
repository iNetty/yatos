/*
 *  IRQ lowleve operations
 *
 *  Copyright (C) 2017 ese@ccnt.zju
 *
 *  ---------------------------------------------------
 *  Started at 2017/3/31 by Ray
 *
 *  ---------------------------------------------------
 *
 *  This file is subject to the terms and conditions of the GNU General Public
 *  License.
 */

#include <arch/irq.h>
#include <arch/system.h>
#include <arch/asm.h>

irq_handler irq_vectors[IRQ_TOTAL_NUM];

void arch_irq_set_handler(int irq_num, irq_handler handler)
{
  irq_vectors[irq_num] = handler;
}

void arch_irq_ack()
{
  pio_out8(0x20, 0xa0);
  pio_out8(0x20, 0x20);
}

//init 8259a
void arch_irq_hard_init()
{
  //master
  pio_out8(0x11, 0x20);
  pio_out8(0x20, 0x21);
  pio_out8(0x04, 0x21);
  pio_out8(0x01, 0x21);
  //slave
  pio_out8(0x11, 0xa0);
  pio_out8(0x28, 0xa1);
  pio_out8(0x04, 0xa1);
  pio_out8(0x01, 0xa1);

}

void arch_irq_init(irq_handler default_handler)
{
  int i;
  for (i = 0; i < IRQ_TOTAL_NUM; i++) {
    arch_irq_set_handler(i, default_handler);
  }
  arch_irq_hard_init();

  irq_init_idt_entry(0, TRAP_TYPE, 0);
  irq_init_idt_entry(1, TRAP_TYPE, 0);
  irq_init_idt_entry(2, TRAP_TYPE, 0);
  irq_init_idt_entry(3, TRAP_TYPE, 0);
  irq_init_idt_entry(4, TRAP_TYPE, 0);
  irq_init_idt_entry(5, TRAP_TYPE, 0);
  irq_init_idt_entry(6, TRAP_TYPE, 0);
  irq_init_idt_entry(7, TRAP_TYPE, 0);
  irq_init_idt_entry(8, TRAP_TYPE, 0);
  irq_init_idt_entry(9, TRAP_TYPE, 0);
  irq_init_idt_entry(10, TRAP_TYPE, 0);
  irq_init_idt_entry(11, TRAP_TYPE, 0);
  irq_init_idt_entry(12, TRAP_TYPE, 0);
  irq_init_idt_entry(13, TRAP_TYPE, 0);
  irq_init_idt_entry(14, TRAP_TYPE, 0);
  irq_init_idt_entry(15, TRAP_TYPE, 0);
  irq_init_idt_entry(16, TRAP_TYPE, 0);
  irq_init_idt_entry(17, TRAP_TYPE, 0);
  irq_init_idt_entry(18, TRAP_TYPE, 0);
  irq_init_idt_entry(19, TRAP_TYPE, 0);
  irq_init_idt_entry(20, INTR_TYPE, 0);
  irq_init_idt_entry(21, INTR_TYPE, 0);
  irq_init_idt_entry(22, INTR_TYPE, 0);
  irq_init_idt_entry(23, INTR_TYPE, 0);
  irq_init_idt_entry(24, INTR_TYPE, 0);
  irq_init_idt_entry(25, INTR_TYPE, 0);
  irq_init_idt_entry(26, INTR_TYPE, 0);
  irq_init_idt_entry(27, INTR_TYPE, 0);
  irq_init_idt_entry(28, INTR_TYPE, 0);
  irq_init_idt_entry(29, INTR_TYPE, 0);
  irq_init_idt_entry(30, INTR_TYPE, 0);
  irq_init_idt_entry(31, INTR_TYPE, 0);
  irq_init_idt_entry(32, INTR_TYPE, 0);
  irq_init_idt_entry(33, INTR_TYPE, 0);
  irq_init_idt_entry(34, INTR_TYPE, 0);
  irq_init_idt_entry(35, INTR_TYPE, 0);
  irq_init_idt_entry(36, INTR_TYPE, 0);
  irq_init_idt_entry(37, INTR_TYPE, 0);
  irq_init_idt_entry(38, INTR_TYPE, 0);
  irq_init_idt_entry(39, INTR_TYPE, 0);
  irq_init_idt_entry(40, INTR_TYPE, 0);
  irq_init_idt_entry(41, INTR_TYPE, 0);
  irq_init_idt_entry(42, INTR_TYPE, 0);
  irq_init_idt_entry(43, INTR_TYPE, 0);
  irq_init_idt_entry(44, INTR_TYPE, 0);
  irq_init_idt_entry(45, INTR_TYPE, 0);
  irq_init_idt_entry(46, INTR_TYPE, 0);
  irq_init_idt_entry(47, INTR_TYPE, 0);
  irq_init_idt_entry(48, INTR_TYPE, 0);
  irq_init_idt_entry(49, INTR_TYPE, 0);
  irq_init_idt_entry(50, INTR_TYPE, 0);
  irq_init_idt_entry(51, INTR_TYPE, 0);
  irq_init_idt_entry(52, INTR_TYPE, 0);
  irq_init_idt_entry(53, INTR_TYPE, 0);
  irq_init_idt_entry(54, INTR_TYPE, 0);
  irq_init_idt_entry(55, INTR_TYPE, 0);
  irq_init_idt_entry(56, INTR_TYPE, 0);
  irq_init_idt_entry(57, INTR_TYPE, 0);
  irq_init_idt_entry(58, INTR_TYPE, 0);
  irq_init_idt_entry(59, INTR_TYPE, 0);
  irq_init_idt_entry(60, INTR_TYPE, 0);
  irq_init_idt_entry(61, INTR_TYPE, 0);
  irq_init_idt_entry(62, INTR_TYPE, 0);
  irq_init_idt_entry(63, INTR_TYPE, 0);
  irq_init_idt_entry(64, INTR_TYPE, 0);
  irq_init_idt_entry(65, INTR_TYPE, 0);
  irq_init_idt_entry(66, INTR_TYPE, 0);
  irq_init_idt_entry(67, INTR_TYPE, 0);
  irq_init_idt_entry(68, INTR_TYPE, 0);
  irq_init_idt_entry(69, INTR_TYPE, 0);
  irq_init_idt_entry(70, INTR_TYPE, 0);
  irq_init_idt_entry(71, INTR_TYPE, 0);
  irq_init_idt_entry(72, INTR_TYPE, 0);
  irq_init_idt_entry(73, INTR_TYPE, 0);
  irq_init_idt_entry(74, INTR_TYPE, 0);
  irq_init_idt_entry(75, INTR_TYPE, 0);
  irq_init_idt_entry(76, INTR_TYPE, 0);
  irq_init_idt_entry(77, INTR_TYPE, 0);
  irq_init_idt_entry(78, INTR_TYPE, 0);
  irq_init_idt_entry(79, INTR_TYPE, 0);
  irq_init_idt_entry(80, INTR_TYPE, 0);
  irq_init_idt_entry(81, INTR_TYPE, 0);
  irq_init_idt_entry(82, INTR_TYPE, 0);
  irq_init_idt_entry(83, INTR_TYPE, 0);
  irq_init_idt_entry(84, INTR_TYPE, 0);
  irq_init_idt_entry(85, INTR_TYPE, 0);
  irq_init_idt_entry(86, INTR_TYPE, 0);
  irq_init_idt_entry(87, INTR_TYPE, 0);
  irq_init_idt_entry(88, INTR_TYPE, 0);
  irq_init_idt_entry(89, INTR_TYPE, 0);
  irq_init_idt_entry(90, INTR_TYPE, 0);
  irq_init_idt_entry(91, INTR_TYPE, 0);
  irq_init_idt_entry(92, INTR_TYPE, 0);
  irq_init_idt_entry(93, INTR_TYPE, 0);
  irq_init_idt_entry(94, INTR_TYPE, 0);
  irq_init_idt_entry(95, INTR_TYPE, 0);
  irq_init_idt_entry(96, INTR_TYPE, 0);
  irq_init_idt_entry(97, INTR_TYPE, 0);
  irq_init_idt_entry(98, INTR_TYPE, 0);
  irq_init_idt_entry(99, INTR_TYPE, 0);
  irq_init_idt_entry(100, INTR_TYPE, 0);
  irq_init_idt_entry(101, INTR_TYPE, 0);
  irq_init_idt_entry(102, INTR_TYPE, 0);
  irq_init_idt_entry(103, INTR_TYPE, 0);
  irq_init_idt_entry(104, INTR_TYPE, 0);
  irq_init_idt_entry(105, INTR_TYPE, 0);
  irq_init_idt_entry(106, INTR_TYPE, 0);
  irq_init_idt_entry(107, INTR_TYPE, 0);
  irq_init_idt_entry(108, INTR_TYPE, 0);
  irq_init_idt_entry(109, INTR_TYPE, 0);
  irq_init_idt_entry(110, INTR_TYPE, 0);
  irq_init_idt_entry(111, INTR_TYPE, 0);
  irq_init_idt_entry(112, INTR_TYPE, 0);
  irq_init_idt_entry(113, INTR_TYPE, 0);
  irq_init_idt_entry(114, INTR_TYPE, 0);
  irq_init_idt_entry(115, INTR_TYPE, 0);
  irq_init_idt_entry(116, INTR_TYPE, 0);
  irq_init_idt_entry(117, INTR_TYPE, 0);
  irq_init_idt_entry(118, INTR_TYPE, 0);
  irq_init_idt_entry(119, INTR_TYPE, 0);
  irq_init_idt_entry(120, INTR_TYPE, 0);
  irq_init_idt_entry(121, INTR_TYPE, 0);
  irq_init_idt_entry(122, INTR_TYPE, 0);
  irq_init_idt_entry(123, INTR_TYPE, 0);
  irq_init_idt_entry(124, INTR_TYPE, 0);
  irq_init_idt_entry(125, INTR_TYPE, 0);
  irq_init_idt_entry(126, INTR_TYPE, 0);
  irq_init_idt_entry(127, INTR_TYPE, 0);
  irq_init_idt_entry(128, INTR_TYPE, 3);
  irq_init_idt_entry(129, INTR_TYPE, 0);
  irq_init_idt_entry(130, INTR_TYPE, 0);
  irq_init_idt_entry(131, INTR_TYPE, 0);
  irq_init_idt_entry(132, INTR_TYPE, 0);
  irq_init_idt_entry(133, INTR_TYPE, 0);
  irq_init_idt_entry(134, INTR_TYPE, 0);
  irq_init_idt_entry(135, INTR_TYPE, 0);
  irq_init_idt_entry(136, INTR_TYPE, 0);
  irq_init_idt_entry(137, INTR_TYPE, 0);
  irq_init_idt_entry(138, INTR_TYPE, 0);
  irq_init_idt_entry(139, INTR_TYPE, 0);
  irq_init_idt_entry(140, INTR_TYPE, 0);
  irq_init_idt_entry(141, INTR_TYPE, 0);
  irq_init_idt_entry(142, INTR_TYPE, 0);
  irq_init_idt_entry(143, INTR_TYPE, 0);
  irq_init_idt_entry(144, INTR_TYPE, 0);
  irq_init_idt_entry(145, INTR_TYPE, 0);
  irq_init_idt_entry(146, INTR_TYPE, 0);
  irq_init_idt_entry(147, INTR_TYPE, 0);
  irq_init_idt_entry(148, INTR_TYPE, 0);
  irq_init_idt_entry(149, INTR_TYPE, 0);
  irq_init_idt_entry(150, INTR_TYPE, 0);
  irq_init_idt_entry(151, INTR_TYPE, 0);
  irq_init_idt_entry(152, INTR_TYPE, 0);
  irq_init_idt_entry(153, INTR_TYPE, 0);
  irq_init_idt_entry(154, INTR_TYPE, 0);
  irq_init_idt_entry(155, INTR_TYPE, 0);
  irq_init_idt_entry(156, INTR_TYPE, 0);
  irq_init_idt_entry(157, INTR_TYPE, 0);
  irq_init_idt_entry(158, INTR_TYPE, 0);
  irq_init_idt_entry(159, INTR_TYPE, 0);
  irq_init_idt_entry(160, INTR_TYPE, 0);
  irq_init_idt_entry(161, INTR_TYPE, 0);
  irq_init_idt_entry(162, INTR_TYPE, 0);
  irq_init_idt_entry(163, INTR_TYPE, 0);
  irq_init_idt_entry(164, INTR_TYPE, 0);
  irq_init_idt_entry(165, INTR_TYPE, 0);
  irq_init_idt_entry(166, INTR_TYPE, 0);
  irq_init_idt_entry(167, INTR_TYPE, 0);
  irq_init_idt_entry(168, INTR_TYPE, 0);
  irq_init_idt_entry(169, INTR_TYPE, 0);
  irq_init_idt_entry(170, INTR_TYPE, 0);
  irq_init_idt_entry(171, INTR_TYPE, 0);
  irq_init_idt_entry(172, INTR_TYPE, 0);
  irq_init_idt_entry(173, INTR_TYPE, 0);
  irq_init_idt_entry(174, INTR_TYPE, 0);
  irq_init_idt_entry(175, INTR_TYPE, 0);
  irq_init_idt_entry(176, INTR_TYPE, 0);
  irq_init_idt_entry(177, INTR_TYPE, 0);
  irq_init_idt_entry(178, INTR_TYPE, 0);
  irq_init_idt_entry(179, INTR_TYPE, 0);
  irq_init_idt_entry(180, INTR_TYPE, 0);
  irq_init_idt_entry(181, INTR_TYPE, 0);
  irq_init_idt_entry(182, INTR_TYPE, 0);
  irq_init_idt_entry(183, INTR_TYPE, 0);
  irq_init_idt_entry(184, INTR_TYPE, 0);
  irq_init_idt_entry(185, INTR_TYPE, 0);
  irq_init_idt_entry(186, INTR_TYPE, 0);
  irq_init_idt_entry(187, INTR_TYPE, 0);
  irq_init_idt_entry(188, INTR_TYPE, 0);
  irq_init_idt_entry(189, INTR_TYPE, 0);
  irq_init_idt_entry(190, INTR_TYPE, 0);
  irq_init_idt_entry(191, INTR_TYPE, 0);
  irq_init_idt_entry(192, INTR_TYPE, 0);
  irq_init_idt_entry(193, INTR_TYPE, 0);
  irq_init_idt_entry(194, INTR_TYPE, 0);
  irq_init_idt_entry(195, INTR_TYPE, 0);
  irq_init_idt_entry(196, INTR_TYPE, 0);
  irq_init_idt_entry(197, INTR_TYPE, 0);
  irq_init_idt_entry(198, INTR_TYPE, 0);
  irq_init_idt_entry(199, INTR_TYPE, 0);
  irq_init_idt_entry(200, INTR_TYPE, 0);
  irq_init_idt_entry(201, INTR_TYPE, 0);
  irq_init_idt_entry(202, INTR_TYPE, 0);
  irq_init_idt_entry(203, INTR_TYPE, 0);
  irq_init_idt_entry(204, INTR_TYPE, 0);
  irq_init_idt_entry(205, INTR_TYPE, 0);
  irq_init_idt_entry(206, INTR_TYPE, 0);
  irq_init_idt_entry(207, INTR_TYPE, 0);
  irq_init_idt_entry(208, INTR_TYPE, 0);
  irq_init_idt_entry(209, INTR_TYPE, 0);
  irq_init_idt_entry(210, INTR_TYPE, 0);
  irq_init_idt_entry(211, INTR_TYPE, 0);
  irq_init_idt_entry(212, INTR_TYPE, 0);
  irq_init_idt_entry(213, INTR_TYPE, 0);
  irq_init_idt_entry(214, INTR_TYPE, 0);
  irq_init_idt_entry(215, INTR_TYPE, 0);
  irq_init_idt_entry(216, INTR_TYPE, 0);
  irq_init_idt_entry(217, INTR_TYPE, 0);
  irq_init_idt_entry(218, INTR_TYPE, 0);
  irq_init_idt_entry(219, INTR_TYPE, 0);
  irq_init_idt_entry(220, INTR_TYPE, 0);
  irq_init_idt_entry(221, INTR_TYPE, 0);
  irq_init_idt_entry(222, INTR_TYPE, 0);
  irq_init_idt_entry(223, INTR_TYPE, 0);
  irq_init_idt_entry(224, INTR_TYPE, 0);
  irq_init_idt_entry(225, INTR_TYPE, 0);
  irq_init_idt_entry(226, INTR_TYPE, 0);
  irq_init_idt_entry(227, INTR_TYPE, 0);
  irq_init_idt_entry(228, INTR_TYPE, 0);
  irq_init_idt_entry(229, INTR_TYPE, 0);
  irq_init_idt_entry(230, INTR_TYPE, 0);
  irq_init_idt_entry(231, INTR_TYPE, 0);
  irq_init_idt_entry(232, INTR_TYPE, 0);
  irq_init_idt_entry(233, INTR_TYPE, 0);
  irq_init_idt_entry(234, INTR_TYPE, 0);
  irq_init_idt_entry(235, INTR_TYPE, 0);
  irq_init_idt_entry(236, INTR_TYPE, 0);
  irq_init_idt_entry(237, INTR_TYPE, 0);
  irq_init_idt_entry(238, INTR_TYPE, 0);
  irq_init_idt_entry(239, INTR_TYPE, 0);
  irq_init_idt_entry(240, INTR_TYPE, 0);
  irq_init_idt_entry(241, INTR_TYPE, 0);
  irq_init_idt_entry(242, INTR_TYPE, 0);
  irq_init_idt_entry(243, INTR_TYPE, 0);
  irq_init_idt_entry(244, INTR_TYPE, 0);
  irq_init_idt_entry(245, INTR_TYPE, 0);
  irq_init_idt_entry(246, INTR_TYPE, 0);
  irq_init_idt_entry(247, INTR_TYPE, 0);
  irq_init_idt_entry(248, INTR_TYPE, 0);
  irq_init_idt_entry(249, INTR_TYPE, 0);
  irq_init_idt_entry(250, INTR_TYPE, 0);
  irq_init_idt_entry(251, INTR_TYPE, 0);
  irq_init_idt_entry(252, INTR_TYPE, 0);
  irq_init_idt_entry(253, INTR_TYPE, 0);
  irq_init_idt_entry(254, INTR_TYPE, 0);
  irq_init_idt_entry(255, INTR_TYPE, 0);
}
