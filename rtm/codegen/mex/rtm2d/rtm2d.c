/*
 * rtm2d.c
 *
 * Code generation for function 'rtm2d'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "rtm2d.h"
#include "rtm2d_emxutil.h"
#include "power.h"
#include "rtm2d_data.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 1, 30, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtRTEInfo b_emlrtRTEI = { 27, 1, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo emlrtBCI = { -1, -1, 34, 21, "data", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 35, 21, "data", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 36, 21, "data", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtRTEInfo d_emlrtRTEI = { 50, 1, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 34, 5, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo emlrtECI = { -1, 34, 1, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 35, 5, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo b_emlrtECI = { -1, 35, 1, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 36, 5, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo c_emlrtECI = { -1, 36, 1, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 56, 39, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 56, 13, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 57, 39, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 57, 13, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 58, 50, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo d_emlrtECI = { 2, 58, 26, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 58, 13, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo e_emlrtECI = { -1, 58, 9, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 59, 50, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo f_emlrtECI = { 2, 59, 26, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 59, 13, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo g_emlrtECI = { -1, 59, 9, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 65, 50, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 65, 17, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo h_emlrtECI = { -1, 65, 13, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 66, 50, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 66, 17, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo i_emlrtECI = { -1, 66, 13, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtECInfo j_emlrtECI = { 2, 79, 20, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtECInfo k_emlrtECI = { -1, 79, 5, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtECInfo l_emlrtECI = { 2, 82, 20, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtECInfo m_emlrtECI = { 2, 83, 11, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtECInfo n_emlrtECI = { 2, 84, 11, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtECInfo o_emlrtECI = { 2, 85, 11, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtECInfo p_emlrtECI = { 2, 86, 11, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtECInfo q_emlrtECI = { -1, 82, 5, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 89, 21, "b", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 89, 32, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo r_emlrtECI = { 2, 89, 19, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo u_emlrtBCI = { -1, -1, 89, 46, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 90, 13, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo w_emlrtBCI = { -1, -1, 90, 26, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo s_emlrtECI = { 2, 90, 11, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 91, 13, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo y_emlrtBCI = { -1, -1, 91, 26, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo t_emlrtECI = { 2, 91, 11, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo ab_emlrtBCI = { -1, -1, 92, 13, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo bb_emlrtBCI = { -1, -1, 92, 24, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo u_emlrtECI = { 2, 92, 11, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 89, 9, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo v_emlrtECI = { -1, 89, 5, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo db_emlrtBCI = { -1, -1, 97, 26, "b", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo eb_emlrtBCI = { -1, -1, 97, 40, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo w_emlrtECI = { 2, 97, 24, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo fb_emlrtBCI = { -1, -1, 97, 55, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo gb_emlrtBCI = { -1, -1, 98, 17, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo hb_emlrtBCI = { -1, -1, 98, 31, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo x_emlrtECI = { 2, 98, 15, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo ib_emlrtBCI = { -1, -1, 99, 17, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo jb_emlrtBCI = { -1, -1, 99, 31, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo y_emlrtECI = { 2, 99, 15, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo kb_emlrtBCI = { -1, -1, 100, 17, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo lb_emlrtBCI = { -1, -1, 100, 31, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo ab_emlrtECI = { 2, 100, 15, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo mb_emlrtBCI = { -1, -1, 97, 13, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo bb_emlrtECI = { -1, 97, 9, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo nb_emlrtBCI = { -1, -1, 103, 28, "b", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo ob_emlrtBCI = { -1, -1, 103, 41, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo pb_emlrtBCI = { -1, -1, 103, 55, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo qb_emlrtBCI = { -1, -1, 104, 20, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo rb_emlrtBCI = { -1, -1, 104, 33, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo sb_emlrtBCI = { -1, -1, 104, 47, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo tb_emlrtBCI = { -1, -1, 104, 62, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo ub_emlrtBCI = { -1, -1, 103, 16, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo vb_emlrtBCI = { -1, -1, 107, 24, "b", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo wb_emlrtBCI = { -1, -1, 107, 37, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo cb_emlrtECI = { -1, 107, 19, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo xb_emlrtBCI = { -1, -1, 107, 51, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo yb_emlrtBCI = { -1, -1, 108, 16, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo ac_emlrtBCI = { -1, -1, 108, 27, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo db_emlrtECI = { -1, 108, 11, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo bc_emlrtBCI = { -1, -1, 109, 18, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo cc_emlrtBCI = { -1, -1, 109, 31, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo eb_emlrtECI = { -1, 109, 11, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo dc_emlrtBCI = { -1, -1, 110, 18, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo ec_emlrtBCI = { -1, -1, 110, 31, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo fb_emlrtECI = { -1, 110, 11, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo fc_emlrtBCI = { -1, -1, 107, 12, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo gb_emlrtECI = { -1, 107, 5, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo gc_emlrtBCI = { -1, -1, 112, 25, "b", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo hc_emlrtBCI = { -1, -1, 112, 39, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo hb_emlrtECI = { -1, 112, 20, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo ic_emlrtBCI = { -1, -1, 112, 54, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo jc_emlrtBCI = { -1, -1, 113, 16, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo kc_emlrtBCI = { -1, -1, 113, 30, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo ib_emlrtECI = { -1, 113, 11, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo lc_emlrtBCI = { -1, -1, 114, 18, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo mc_emlrtBCI = { -1, -1, 114, 32, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo jb_emlrtECI = { -1, 114, 11, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo nc_emlrtBCI = { -1, -1, 115, 18, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo oc_emlrtBCI = { -1, -1, 115, 32, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo kb_emlrtECI = { -1, 115, 11, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo pc_emlrtBCI = { -1, -1, 112, 12, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo lb_emlrtECI = { -1, 112, 5, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo qc_emlrtBCI = { -1, -1, 118, 20, "b", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo rc_emlrtBCI = { -1, -1, 118, 22, "b", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo sc_emlrtBCI = { -1, -1, 118, 32, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo tc_emlrtBCI = { -1, -1, 118, 34, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo uc_emlrtBCI = { -1, -1, 118, 45, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo vc_emlrtBCI = { -1, -1, 118, 47, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo wc_emlrtBCI = { -1, -1, 119, 13, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo xc_emlrtBCI = { -1, -1, 119, 15, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo yc_emlrtBCI = { -1, -1, 119, 25, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo ad_emlrtBCI = { -1, -1, 119, 27, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo bd_emlrtBCI = { -1, -1, 119, 36, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo cd_emlrtBCI = { -1, -1, 119, 38, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo dd_emlrtBCI = { -1, -1, 119, 48, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo ed_emlrtBCI = { -1, -1, 119, 50, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo fd_emlrtBCI = { -1, -1, 118, 9, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo gd_emlrtBCI = { -1, -1, 118, 11, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo hd_emlrtBCI = { -1, -1, 122, 21, "b", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo id_emlrtBCI = { -1, -1, 122, 34, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo jd_emlrtBCI = { -1, -1, 122, 48, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo kd_emlrtBCI = { -1, -1, 123, 13, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo ld_emlrtBCI = { -1, -1, 123, 28, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo md_emlrtBCI = { -1, -1, 123, 42, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo nd_emlrtBCI = { -1, -1, 123, 55, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo od_emlrtBCI = { -1, -1, 122, 9, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo mb_emlrtECI = { -1, 126, 5, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtECInfo nb_emlrtECI = { -1, 127, 5, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo pd_emlrtBCI = { -1, -1, 131, 13, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo qd_emlrtBCI = { -1, -1, 132, 29, "data", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo rd_emlrtBCI = { -1, -1, 132, 13, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo ob_emlrtECI = { -1, 132, 9, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo sd_emlrtBCI = { -1, -1, 145, 18, "snapshot", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtECInfo pb_emlrtECI = { -1, 145, 5, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m" };

static emlrtBCInfo td_emlrtBCI = { -1, -1, 79, 24, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtDCInfo emlrtDCI = { 79, 24, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 1 };

static emlrtBCInfo ud_emlrtBCI = { -1, -1, 79, 27, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtDCInfo b_emlrtDCI = { 79, 27, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 1 };

static emlrtBCInfo vd_emlrtBCI = { -1, -1, 79, 39, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo wd_emlrtBCI = { -1, -1, 79, 42, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo xd_emlrtBCI = { -1, -1, 79, 9, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo yd_emlrtBCI = { -1, -1, 79, 12, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo ae_emlrtBCI = { -1, -1, 82, 22, "b", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtDCInfo c_emlrtDCI = { 82, 22, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 1 };

static emlrtBCInfo be_emlrtBCI = { -1, -1, 82, 25, "b", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo ce_emlrtBCI = { -1, -1, 82, 34, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo de_emlrtBCI = { -1, -1, 82, 37, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo ee_emlrtBCI = { -1, -1, 82, 49, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo fe_emlrtBCI = { -1, -1, 82, 52, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo ge_emlrtBCI = { -1, -1, 83, 13, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo he_emlrtBCI = { -1, -1, 83, 16, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo ie_emlrtBCI = { -1, -1, 83, 27, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo je_emlrtBCI = { -1, -1, 83, 30, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo ke_emlrtBCI = { -1, -1, 84, 13, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo le_emlrtBCI = { -1, -1, 84, 16, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo me_emlrtBCI = { -1, -1, 84, 27, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo ne_emlrtBCI = { -1, -1, 84, 30, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo oe_emlrtBCI = { -1, -1, 85, 13, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo pe_emlrtBCI = { -1, -1, 85, 18, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo qe_emlrtBCI = { -1, -1, 85, 27, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo re_emlrtBCI = { -1, -1, 85, 32, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo se_emlrtBCI = { -1, -1, 86, 13, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo te_emlrtBCI = { -1, -1, 86, 18, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo ue_emlrtBCI = { -1, -1, 86, 27, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo ve_emlrtBCI = { -1, -1, 86, 32, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo we_emlrtBCI = { -1, -1, 82, 9, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo xe_emlrtBCI = { -1, -1, 82, 12, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo ye_emlrtBCI = { -1, -1, 89, 23, "b", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo af_emlrtBCI = { -1, -1, 89, 34, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo bf_emlrtBCI = { -1, -1, 89, 48, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo cf_emlrtBCI = { -1, -1, 90, 15, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo df_emlrtBCI = { -1, -1, 90, 28, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo ef_emlrtBCI = { -1, -1, 91, 15, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo ff_emlrtBCI = { -1, -1, 91, 28, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo gf_emlrtBCI = { -1, -1, 92, 15, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo hf_emlrtBCI = { -1, -1, 92, 26, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo if_emlrtBCI = { -1, -1, 89, 11, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo jf_emlrtBCI = { -1, -1, 97, 29, "b", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo kf_emlrtBCI = { -1, -1, 97, 43, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo lf_emlrtBCI = { -1, -1, 97, 58, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo mf_emlrtBCI = { -1, -1, 98, 20, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo nf_emlrtBCI = { -1, -1, 98, 34, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo of_emlrtBCI = { -1, -1, 99, 20, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo pf_emlrtBCI = { -1, -1, 99, 34, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo qf_emlrtBCI = { -1, -1, 100, 22, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo rf_emlrtBCI = { -1, -1, 100, 36, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo sf_emlrtBCI = { -1, -1, 97, 16, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo tf_emlrtBCI = { -1, -1, 103, 13, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo uf_emlrtBCI = { -1, -1, 103, 25, "b", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo vf_emlrtBCI = { -1, -1, 103, 38, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo wf_emlrtBCI = { -1, -1, 103, 52, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo xf_emlrtBCI = { -1, -1, 104, 17, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo yf_emlrtBCI = { -1, -1, 104, 30, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo ag_emlrtBCI = { -1, -1, 104, 42, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo bg_emlrtBCI = { -1, -1, 104, 57, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo cg_emlrtBCI = { -1, -1, 107, 21, "b", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo dg_emlrtBCI = { -1, -1, 107, 34, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo eg_emlrtBCI = { -1, -1, 107, 48, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo fg_emlrtBCI = { -1, -1, 108, 13, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo gg_emlrtBCI = { -1, -1, 108, 24, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo hg_emlrtBCI = { -1, -1, 109, 13, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo ig_emlrtBCI = { -1, -1, 109, 26, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo jg_emlrtBCI = { -1, -1, 110, 13, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo kg_emlrtBCI = { -1, -1, 110, 26, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo lg_emlrtBCI = { -1, -1, 107, 9, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo mg_emlrtBCI = { -1, -1, 112, 22, "b", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo ng_emlrtBCI = { -1, -1, 112, 36, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo og_emlrtBCI = { -1, -1, 112, 51, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo pg_emlrtBCI = { -1, -1, 113, 13, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo qg_emlrtBCI = { -1, -1, 113, 27, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo rg_emlrtBCI = { -1, -1, 114, 13, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo sg_emlrtBCI = { -1, -1, 114, 27, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo tg_emlrtBCI = { -1, -1, 115, 13, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo ug_emlrtBCI = { -1, -1, 115, 27, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo vg_emlrtBCI = { -1, -1, 112, 9, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo wg_emlrtBCI = { -1, -1, 122, 11, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo xg_emlrtBCI = { -1, -1, 122, 23, "b", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo yg_emlrtBCI = { -1, -1, 122, 36, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo ah_emlrtBCI = { -1, -1, 122, 50, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo bh_emlrtBCI = { -1, -1, 123, 15, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo ch_emlrtBCI = { -1, -1, 123, 30, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo dh_emlrtBCI = { -1, -1, 123, 44, "a", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo eh_emlrtBCI = { -1, -1, 123, 57, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo fh_emlrtBCI = { 1, 20, 65, 27, "boundary", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo gh_emlrtBCI = { 1, 20, 66, 27, "boundary", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo hh_emlrtBCI = { -1, -1, 56, 42, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo ih_emlrtBCI = { -1, -1, 56, 16, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo jh_emlrtBCI = { -1, -1, 57, 42, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo kh_emlrtBCI = { -1, -1, 57, 16, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo lh_emlrtBCI = { -1, -1, 58, 53, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtDCInfo d_emlrtDCI = { 58, 53, "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 1 };

static emlrtBCInfo mh_emlrtBCI = { -1, -1, 58, 16, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo nh_emlrtBCI = { -1, -1, 59, 53, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

static emlrtBCInfo oh_emlrtBCI = { -1, -1, 59, 16, "fdm", "rtm2d",
  "/home/atupal/src/sc14/seismicCompetition/rtm/rtm2d.m", 0 };

/* Function Definitions */
void rtm2d(rtm2dStackData *SD, const emlrtStack *sp, const real_T v_data[],
           const int32_T v_size[2], const emxArray_real_T *data, real_T dx,
           real_T dt, real_T model_data[], int32_T model_size[2],
           emxArray_real_T *snapshot)
{
  emxArray_real_T *fdm;
  boolean_T b0;
  boolean_T b1;
  int32_T i0;
  int32_T loop_ub;
  real_T boundary[20];
  static const real_T dv0[20] = { 0.92198622120531026, 0.92969379475695435,
    0.93704403698365013, 0.94402748291783567, 0.95063509185869843,
    0.95685826686190967, 0.96268887336852249, 0.96811925691656275,
    0.9731422598813525, 0.97775123719333634, 0.98194007098510672,
    0.985703184122443, 0.98903555257747811, 0.99193271660557114,
    0.99439079069108094, 0.99640647223099332, 0.99797704892923944,
    0.99910040487852736, 0.99977502531060169, 1.0 };

  int32_T tmp_data[50];
  int32_T i1;
  int32_T iv0[2];
  int32_T b_data[1];
  int32_T absb;
  real_T data_data[50];
  int32_T b_fdm[2];
  int32_T c_data[1];
  int32_T apnd;
  int32_T c_fdm[2];
  int32_T d_data[1];
  int32_T b_v_size[2];
  int32_T a_size[2];
  int32_T n;
  int32_T ndbl;
  int32_T cdiff;
  real_T y_data[119];
  int32_T b_n;
  int32_T ez;
  real_T ixb2_data[70];
  real_T cz;
  int32_T it;
  int32_T b_it;
  int32_T bz;
  real_T b_boundary[20];
  int32_T i2;
  int8_T fdm_size[2];
  int32_T b_tmp_data[70];
  int32_T iv1[2];
  int32_T iv2[2];
  real_T fdm_data[70];
  int8_T b_fdm_size[2];
  int32_T iv3[2];
  int32_T iv4[2];
  int32_T tmp_size[2];
  real_T c_tmp_data[50];
  int32_T iv5[2];
  int32_T iv6[2];
  int32_T c_n;
  real_T iz_data[120];
  int32_T c_fdm_size[2];
  int32_T d_fdm_size[2];
  int32_T d_tmp_data[120];
  int32_T e_tmp_data[48];
  int32_T iv7[2];
  int32_T e_fdm_size[2];
  real_T b_y_data[119];
  int32_T b_size[2];
  int32_T f_fdm_size[2];
  int32_T b_tmp_size[2];
  int32_T g_fdm_size[2];
  int32_T c_tmp_size[2];
  int32_T b_a_size[2];
  int32_T h_fdm_size[2];
  int32_T d_tmp_size[2];
  real_T f_tmp_data[5712];
  int32_T c_a_size[2];
  int32_T i_fdm_size[2];
  int32_T e_tmp_size[2];
  real_T g_tmp_data[5712];
  int32_T d_a_size[2];
  int32_T j_fdm_size[2];
  int32_T f_tmp_size[2];
  real_T h_tmp_data[5712];
  int32_T e_a_size[2];
  int32_T k_fdm_size[2];
  int32_T i_tmp_data[119];
  int32_T iv8[2];
  real_T j_tmp_data[5712];
  int32_T b_b_size[2];
  int32_T l_fdm_size[2];
  int32_T g_tmp_size[2];
  real_T k_tmp_data[48];
  int32_T m_fdm_size[2];
  int32_T h_tmp_size[2];
  real_T l_tmp_data[48];
  real_T m_tmp_data[48];
  int32_T f_a_size[2];
  int32_T n_fdm_size[2];
  int32_T i_tmp_size[2];
  real_T n_tmp_data[48];
  int32_T g_a_size[2];
  int32_T o_fdm_size[2];
  int32_T h_a_size[2];
  int32_T p_fdm_size[2];
  int32_T j_tmp_size[2];
  int32_T iv9[2];
  real_T o_tmp_data[48];
  int32_T c_b_size[2];
  int32_T q_fdm_size[2];
  int32_T r_fdm_size[2];
  int32_T i_a_size[2];
  int32_T s_fdm_size[2];
  int32_T j_a_size[2];
  int32_T t_fdm_size[2];
  int32_T k_a_size[2];
  int32_T u_fdm_size[2];
  int32_T iv10[2];
  int32_T k_tmp_size[1];
  real_T p_tmp_data[119];
  real_T q_tmp_data[119];
  real_T r_tmp_data[119];
  real_T s_tmp_data[119];
  real_T t_tmp_data[119];
  int32_T iv11[1];
  real_T u_tmp_data[119];
  int32_T iv12[1];
  int32_T iv13[2];
  int32_T v_fdm_size[2];
  int32_T iv14[2];
  int32_T w_fdm_size[2];
  int32_T iv15[2];
  int32_T e_data[1];
  int32_T iv16[2];
  int32_T x_fdm_size[2];
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &fdm, 3, &b_emlrtRTEI, true);
  b0 = false;
  b1 = false;

  /*  */
  /*  data(nx,nt)       data vector */
  /*  v(nz,nx)          velocity model */
  /*  nx                number of horizontal samples */
  /*  nz                number of depth samples */
  /*  nt                numer of time samples */
  /*  dx                horizontal distance per sample */
  /*  dz                depth distance per sample */
  /*  dt                time difference per sample */
  /*  add grid points for boundary condition */
  /* v = [repmat(v(:,1),1,20), v, repmat(v(:,end),1,20)]; */
  /* v(end+20,:) = v(end,:); */
  /* % Initialize storage */
  i0 = fdm->size[0] * fdm->size[1] * fdm->size[2];
  fdm->size[0] = v_size[0];
  emxEnsureCapacity(sp, (emxArray__common *)fdm, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  i0 = fdm->size[0] * fdm->size[1] * fdm->size[2];
  fdm->size[1] = v_size[1];
  fdm->size[2] = 3;
  emxEnsureCapacity(sp, (emxArray__common *)fdm, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = v_size[0] * v_size[1] * 3;
  for (i0 = 0; i0 < loop_ub; i0++) {
    fdm->data[i0] = 0.0;
  }

  /* % Boundary Absorbing Model */
  power(dv0, boundary);

  /* % Reverse-Time Migration */
  emlrtDynamicBoundsCheckFastR2012b(1, 1, v_size[0], &d_emlrtBCI, sp);
  loop_ub = v_size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    tmp_data[i0] = i0;
  }

  i0 = data->size[1];
  i1 = data->size[1];
  emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &emlrtBCI, sp);
  iv0[0] = 1;
  iv0[1] = v_size[1];
  i0 = data->size[0];
  b_data[0] = i0;
  emlrtSubAssignSizeCheckR2012b(iv0, 2, b_data, 1, &emlrtECI, sp);
  loop_ub = data->size[0];
  absb = data->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    data_data[i0] = data->data[i0 + data->size[0] * (absb - 1)];
  }

  loop_ub = v_size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    fdm->data[fdm->size[0] * tmp_data[i0]] = data_data[i0];
  }

  i0 = fdm->size[0];
  emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &e_emlrtBCI, sp);
  loop_ub = fdm->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    tmp_data[i0] = i0;
  }

  i0 = data->size[1];
  i1 = (int32_T)((real_T)data->size[1] - 1.0);
  emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &b_emlrtBCI, sp);
  b_fdm[0] = 1;
  b_fdm[1] = loop_ub;
  i0 = data->size[0];
  c_data[0] = i0;
  emlrtSubAssignSizeCheckR2012b(b_fdm, 2, c_data, 1, &b_emlrtECI, sp);
  apnd = data->size[0];
  absb = data->size[1];
  for (i0 = 0; i0 < apnd; i0++) {
    data_data[i0] = data->data[i0 + data->size[0] * (absb - 2)];
  }

  for (i0 = 0; i0 < loop_ub; i0++) {
    fdm->data[fdm->size[0] * tmp_data[i0] + fdm->size[0] * fdm->size[1]] =
      data_data[i0];
  }

  i0 = fdm->size[0];
  emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &f_emlrtBCI, sp);
  loop_ub = fdm->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    tmp_data[i0] = i0;
  }

  i0 = data->size[1];
  i1 = (int32_T)((real_T)data->size[1] - 2.0);
  emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &c_emlrtBCI, sp);
  c_fdm[0] = 1;
  c_fdm[1] = loop_ub;
  i0 = data->size[0];
  d_data[0] = i0;
  emlrtSubAssignSizeCheckR2012b(c_fdm, 2, d_data, 1, &c_emlrtECI, sp);
  apnd = data->size[0];
  absb = data->size[1];
  for (i0 = 0; i0 < apnd; i0++) {
    data_data[i0] = data->data[i0 + data->size[0] * (absb - 3)];
  }

  for (i0 = 0; i0 < loop_ub; i0++) {
    fdm->data[fdm->size[0] * tmp_data[i0] + (fdm->size[0] * fdm->size[1] << 1)] =
      data_data[i0];
  }

  /*  finite difference coefficients */
  b_v_size[0] = v_size[0];
  b_v_size[1] = v_size[1];
  loop_ub = v_size[0] * v_size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    SD->f0.v_data[i0] = v_data[i0] * dt / dx;
  }

  b_power(SD->f0.v_data, b_v_size, SD->f0.a_data, a_size);

  /*  wave equation coefficient */
  loop_ub = a_size[0] * a_size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    SD->f0.b_data[i0] = 2.0 - 4.0 * SD->f0.a_data[i0];
  }

  /*  common indicies */
  if (v_size[1] - 1 < 2) {
    n = -1;
    apnd = v_size[1] - 1;
  } else {
    ndbl = (int32_T)muDoubleScalarFloor((((real_T)v_size[1] - 1.0) - 2.0) + 0.5);
    apnd = ndbl + 2;
    cdiff = (ndbl - v_size[1]) + 3;
    absb = (int32_T)muDoubleScalarAbs((real_T)v_size[1] - 1.0);
    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)
        muIntScalarMax_sint32(2, absb)) {
      ndbl++;
      apnd = v_size[1] - 1;
    } else if (cdiff > 0) {
      apnd = ndbl + 1;
    } else {
      ndbl++;
    }

    n = ndbl - 1;
  }

  if (n + 1 > 0) {
    y_data[0] = 2.0;
    if (n + 1 > 1) {
      y_data[n] = apnd;
      i0 = n + (n < 0);
      if (i0 >= 0) {
        absb = (int32_T)((uint32_T)i0 >> 1);
      } else {
        absb = ~(int32_T)((uint32_T)~i0 >> 1);
      }

      for (ndbl = 1; ndbl < absb; ndbl++) {
        y_data[ndbl] = 2.0 + (real_T)ndbl;
        y_data[n - ndbl] = apnd - ndbl;
      }

      if (absb << 1 == n) {
        y_data[absb] = (2.0 + (real_T)apnd) / 2.0;
      } else {
        y_data[absb] = 2.0 + (real_T)absb;
        y_data[absb + 1] = apnd - absb;
      }
    }
  }

  /*  interior x */
  /*  boundary x (right) */
  if (v_size[1] < v_size[1] - 19) {
    b_n = -1;
    ez = v_size[1] - 19;
    apnd = v_size[1];
  } else {
    ez = v_size[1] - 19;
    ndbl = 19;
    apnd = v_size[1];
    cdiff = apnd - v_size[1];
    absb = (int32_T)muDoubleScalarAbs((real_T)v_size[1] - 19.0);
    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)
        muIntScalarMax_sint32(absb, v_size[1])) {
      ndbl = 20;
      apnd = v_size[1];
    } else if (cdiff > 0) {
      apnd = v_size[1] - 1;
    } else {
      ndbl = 20;
    }

    b_n = ndbl - 1;
  }

  if (b_n + 1 > 0) {
    ixb2_data[0] = ez;
    if (b_n + 1 > 1) {
      ixb2_data[b_n] = apnd;
      i0 = b_n + (b_n < 0);
      if (i0 >= 0) {
        absb = (int32_T)((uint32_T)i0 >> 1);
      } else {
        absb = ~(int32_T)((uint32_T)~i0 >> 1);
      }

      for (ndbl = 1; ndbl < absb; ndbl++) {
        ixb2_data[ndbl] = ez + ndbl;
        ixb2_data[b_n - ndbl] = apnd - ndbl;
      }

      if (absb << 1 == b_n) {
        ixb2_data[absb] = (real_T)(ez + apnd) / 2.0;
      } else {
        ixb2_data[absb] = ez + absb;
        ixb2_data[absb + 1] = apnd - absb;
      }
    }
  }

  /*  boundary x (left) */
  cz = 3.0;
  i0 = snapshot->size[0] * snapshot->size[1] * snapshot->size[2];
  snapshot->size[0] = v_size[0];
  emxEnsureCapacity(sp, (emxArray__common *)snapshot, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  i0 = snapshot->size[0] * snapshot->size[1] * snapshot->size[2];
  snapshot->size[1] = v_size[1];
  emxEnsureCapacity(sp, (emxArray__common *)snapshot, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  absb = data->size[1];
  i0 = snapshot->size[0] * snapshot->size[1] * snapshot->size[2];
  snapshot->size[2] = absb;
  emxEnsureCapacity(sp, (emxArray__common *)snapshot, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = v_size[0] * v_size[1] * data->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    snapshot->data[i0] = 0.0;
  }

  emlrtForLoopVectorCheckR2012b((real_T)data->size[1] - 1.0, -1.0, 1.0,
    mxDOUBLE_CLASS, data->size[1] - 1, &d_emlrtRTEI, sp);
  it = 0;
  while (it <= data->size[1] - 2) {
    b_it = (data->size[1] - it) - 1;
    cz++;
    bz = (int32_T)muDoubleScalarMin(cz, v_size[0]);

    /*  apply absorbing boundary condition on left/right sides */
    cdiff = 0;
    while (cdiff <= bz - 1) {
      absb = fdm->size[0];
      ez = fdm->size[1];
      i0 = 1 + cdiff;
      emlrtDynamicBoundsCheckFastR2012b(i0, 1, absb, &h_emlrtBCI, sp);
      absb = fdm->size[0];
      ndbl = fdm->size[1];
      i0 = 1 + cdiff;
      emlrtDynamicBoundsCheckFastR2012b(i0, 1, absb, &g_emlrtBCI, sp);
      for (i0 = 0; i0 < 20; i0++) {
        i1 = 1 + i0;
        b_boundary[i0] = boundary[i0] * fdm->data[cdiff + fdm->size[0] *
          (emlrtDynamicBoundsCheckFastR2012b(i1, 1, ndbl, &hh_emlrtBCI, sp) - 1)];
      }

      for (i0 = 0; i0 < 20; i0++) {
        i1 = 1 + i0;
        fdm->data[cdiff + fdm->size[0] * (emlrtDynamicBoundsCheckFastR2012b(i1,
          1, ez, &ih_emlrtBCI, sp) - 1)] = b_boundary[i0];
      }

      absb = fdm->size[0];
      ez = fdm->size[1];
      i0 = 1 + cdiff;
      emlrtDynamicBoundsCheckFastR2012b(i0, 1, absb, &j_emlrtBCI, sp);
      absb = fdm->size[0];
      ndbl = fdm->size[1];
      i0 = 1 + cdiff;
      emlrtDynamicBoundsCheckFastR2012b(i0, 1, absb, &i_emlrtBCI, sp);
      for (i0 = 0; i0 < 20; i0++) {
        i1 = 1 + i0;
        b_boundary[i0] = boundary[i0] * fdm->data[(cdiff + fdm->size[0] *
          (emlrtDynamicBoundsCheckFastR2012b(i1, 1, ndbl, &jh_emlrtBCI, sp) - 1))
          + fdm->size[0] * fdm->size[1]];
      }

      for (i0 = 0; i0 < 20; i0++) {
        i1 = 1 + i0;
        fdm->data[(cdiff + fdm->size[0] * (emlrtDynamicBoundsCheckFastR2012b(i1,
          1, ez, &kh_emlrtBCI, sp) - 1)) + fdm->size[0] * fdm->size[1]] =
          b_boundary[i0];
      }

      i0 = fdm->size[0];
      i1 = cdiff + 1;
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &k_emlrtBCI, sp);
      loop_ub = b_n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        i1 = fdm->size[1];
        i2 = (int32_T)emlrtIntegerCheckFastR2012b(ixb2_data[i0], &d_emlrtDCI, sp);
        emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &lh_emlrtBCI, sp);
      }

      fdm_size[0] = 1;
      fdm_size[1] = (int8_T)(b_n + 1);
      for (i0 = 0; i0 < 2; i0++) {
        iv0[i0] = 1 + 19 * i0;
        b_fdm[i0] = fdm_size[i0];
      }

      emlrtSizeEqCheck2DFastR2012b(iv0, b_fdm, &d_emlrtECI, sp);
      i0 = fdm->size[0];
      i1 = cdiff + 1;
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &l_emlrtBCI, sp);
      loop_ub = b_n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        i1 = fdm->size[1];
        i2 = (int32_T)ixb2_data[i0];
        b_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
          &mh_emlrtBCI, sp) - 1;
      }

      iv1[0] = 1;
      iv1[1] = b_n + 1;
      if (!b0) {
        for (i0 = 0; i0 < 2; i0++) {
          iv2[i0] = 1 + 19 * i0;
        }

        b0 = true;
      }

      emlrtSubAssignSizeCheckR2012b(iv1, 2, iv2, 2, &e_emlrtECI, sp);
      loop_ub = b_n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        fdm_data[i0] = fdm->data[cdiff + fdm->size[0] * ((int32_T)ixb2_data[i0]
          - 1)];
      }

      for (i0 = 0; i0 < 20; i0++) {
        b_boundary[i0] = boundary[19 - i0] * fdm_data[i0];
      }

      loop_ub = b_n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        fdm->data[cdiff + fdm->size[0] * b_tmp_data[i0]] = b_boundary[i0];
      }

      i0 = fdm->size[0];
      i1 = cdiff + 1;
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &m_emlrtBCI, sp);
      loop_ub = b_n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        i1 = fdm->size[1];
        i2 = (int32_T)ixb2_data[i0];
        emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &nh_emlrtBCI, sp);
      }

      b_fdm_size[0] = 1;
      b_fdm_size[1] = (int8_T)(b_n + 1);
      for (i0 = 0; i0 < 2; i0++) {
        iv0[i0] = 1 + 19 * i0;
        b_fdm[i0] = b_fdm_size[i0];
      }

      emlrtSizeEqCheck2DFastR2012b(iv0, b_fdm, &f_emlrtECI, sp);
      i0 = fdm->size[0];
      i1 = cdiff + 1;
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &n_emlrtBCI, sp);
      loop_ub = b_n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        i1 = fdm->size[1];
        i2 = (int32_T)ixb2_data[i0];
        b_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
          &oh_emlrtBCI, sp) - 1;
      }

      iv3[0] = 1;
      iv3[1] = b_n + 1;
      if (!b1) {
        for (i0 = 0; i0 < 2; i0++) {
          iv4[i0] = 1 + 19 * i0;
        }

        b1 = true;
      }

      emlrtSubAssignSizeCheckR2012b(iv3, 2, iv4, 2, &g_emlrtECI, sp);
      loop_ub = b_n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        fdm_data[i0] = fdm->data[(cdiff + fdm->size[0] * ((int32_T)ixb2_data[i0]
          - 1)) + fdm->size[0] * fdm->size[1]];
      }

      for (i0 = 0; i0 < 20; i0++) {
        b_boundary[i0] = boundary[19 - i0] * fdm_data[i0];
      }

      loop_ub = b_n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        fdm->data[(cdiff + fdm->size[0] * b_tmp_data[i0]) + fdm->size[0] *
          fdm->size[1]] = b_boundary[i0];
      }

      cdiff++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
    }

    /*  apply absorbing boundary condition at depth nz */
    if (bz >= v_size[0] - 19) {
      i0 = (bz - v_size[0]) + 19;
      cdiff = 0;
      while (cdiff <= i0) {
        ez = (v_size[0] + cdiff) - 20;
        i1 = fdm->size[0];
        i2 = ez + 1;
        emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &p_emlrtBCI, sp);
        loop_ub = fdm->size[1];
        for (i1 = 0; i1 < loop_ub; i1++) {
          tmp_data[i1] = i1;
        }

        i1 = v_size[0] - ez;
        emlrtDynamicBoundsCheckFastR2012b(i1, 1, 20, &fh_emlrtBCI, sp);
        apnd = fdm->size[1];
        i1 = fdm->size[0];
        absb = emlrtDynamicBoundsCheckFastR2012b(ez + 1, 1, i1, &o_emlrtBCI, sp);
        tmp_size[0] = 1;
        tmp_size[1] = apnd;
        for (i1 = 0; i1 < apnd; i1++) {
          c_tmp_data[i1] = boundary[(v_size[0] - ez) - 1] * fdm->data[(absb +
            fdm->size[0] * i1) - 1];
        }

        iv5[0] = 1;
        iv5[1] = loop_ub;
        emlrtSubAssignSizeCheckR2012b(iv5, 2, tmp_size, 2, &h_emlrtECI, sp);
        for (i1 = 0; i1 < apnd; i1++) {
          fdm->data[ez + fdm->size[0] * tmp_data[i1]] = c_tmp_data[i1];
        }

        i1 = fdm->size[0];
        i2 = ez + 1;
        emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &r_emlrtBCI, sp);
        loop_ub = fdm->size[1];
        for (i1 = 0; i1 < loop_ub; i1++) {
          tmp_data[i1] = i1;
        }

        i1 = v_size[0] - ez;
        emlrtDynamicBoundsCheckFastR2012b(i1, 1, 20, &gh_emlrtBCI, sp);
        apnd = fdm->size[1];
        i1 = fdm->size[0];
        absb = emlrtDynamicBoundsCheckFastR2012b(ez + 1, 1, i1, &q_emlrtBCI, sp);
        tmp_size[0] = 1;
        tmp_size[1] = apnd;
        for (i1 = 0; i1 < apnd; i1++) {
          c_tmp_data[i1] = boundary[(v_size[0] - ez) - 1] * fdm->data[((absb +
            fdm->size[0] * i1) + fdm->size[0] * fdm->size[1]) - 1];
        }

        iv6[0] = 1;
        iv6[1] = loop_ub;
        emlrtSubAssignSizeCheckR2012b(iv6, 2, tmp_size, 2, &i_emlrtECI, sp);
        for (i1 = 0; i1 < apnd; i1++) {
          fdm->data[(ez + fdm->size[0] * tmp_data[i1]) + fdm->size[0] *
            fdm->size[1]] = c_tmp_data[i1];
        }

        cdiff++;
        emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
      }
    }

    /*  computing grid depth (extend in z to solve) */
    if (bz == v_size[0]) {
      ez = v_size[0] - 1;
    } else {
      ez = bz;
    }

    /*  time extrapolation between iz and bz */
    if (bz < 1) {
      c_n = -1;
      apnd = 0;
    } else {
      ndbl = (int32_T)muDoubleScalarFloor(((real_T)bz - 1.0) + 0.5);
      apnd = ndbl + 1;
      cdiff = (ndbl - bz) + 1;
      if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)bz) {
        ndbl++;
        apnd = bz;
      } else if (cdiff > 0) {
        apnd = ndbl;
      } else {
        ndbl++;
      }

      c_n = ndbl - 1;
    }

    if (c_n + 1 > 0) {
      iz_data[0] = 1.0;
      if (c_n + 1 > 1) {
        iz_data[c_n] = apnd;
        i0 = c_n + (c_n < 0);
        if (i0 >= 0) {
          absb = (int32_T)((uint32_T)i0 >> 1);
        } else {
          absb = ~(int32_T)((uint32_T)~i0 >> 1);
        }

        for (ndbl = 1; ndbl < absb; ndbl++) {
          iz_data[ndbl] = 1.0 + (real_T)ndbl;
          iz_data[c_n - ndbl] = apnd - ndbl;
        }

        if (absb << 1 == c_n) {
          iz_data[absb] = (1.0 + (real_T)apnd) / 2.0;
        } else {
          iz_data[absb] = 1.0 + (real_T)absb;
          iz_data[absb + 1] = apnd - absb;
        }
      }
    }

    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)emlrtIntegerCheckFastR2012b(iz_data[i0], &emlrtDCI, sp);
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &td_emlrtBCI, sp);
    }

    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[1];
      i2 = (int32_T)emlrtIntegerCheckFastR2012b(y_data[i0], &b_emlrtDCI, sp);
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &ud_emlrtBCI, sp);
    }

    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)iz_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &vd_emlrtBCI, sp);
    }

    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[1];
      i2 = (int32_T)y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &wd_emlrtBCI, sp);
    }

    c_fdm_size[0] = c_n + 1;
    c_fdm_size[1] = n + 1;
    d_fdm_size[0] = c_n + 1;
    d_fdm_size[1] = n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      b_fdm[i0] = c_fdm_size[i0];
      c_fdm[i0] = d_fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(b_fdm, c_fdm, &j_emlrtECI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)iz_data[i0];
      d_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &xd_emlrtBCI,
        sp) - 1;
    }

    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[1];
      i2 = (int32_T)y_data[i0];
      e_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &yd_emlrtBCI,
        sp) - 1;
    }

    iv7[0] = c_n + 1;
    iv7[1] = n + 1;
    e_fdm_size[0] = c_n + 1;
    e_fdm_size[1] = n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      b_fdm[i0] = e_fdm_size[i0];
    }

    emlrtSubAssignSizeCheckR2012b(iv7, 2, b_fdm, 2, &k_emlrtECI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      apnd = c_n + 1;
      for (i1 = 0; i1 < apnd; i1++) {
        SD->f0.fdm_data[i1 + (c_n + 1) * i0] = fdm->data[(((int32_T)iz_data[i1]
          + fdm->size[0] * ((int32_T)y_data[i0] - 1)) + (fdm->size[0] *
          fdm->size[1] << 1)) - 1] - fdm->data[((int32_T)iz_data[i1] + fdm->
          size[0] * ((int32_T)y_data[i0] - 1)) - 1];
      }
    }

    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      apnd = c_n + 1;
      for (i1 = 0; i1 < apnd; i1++) {
        fdm->data[(d_tmp_data[i1] + fdm->size[0] * e_tmp_data[i0]) + (fdm->size
          [0] * fdm->size[1] << 1)] = SD->f0.fdm_data[i1 + (c_n + 1) * i0];
      }
    }

    if (ez < 2) {
      c_n = -1;
      apnd = ez;
    } else {
      ndbl = (int32_T)muDoubleScalarFloor(((real_T)ez - 2.0) + 0.5) + 2;
      apnd = ndbl;
      cdiff = ndbl - ez;
      if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)ez) {
        ndbl++;
        apnd = ez;
      } else if (cdiff > 0) {
        apnd = ndbl - 1;
      } else {
        ndbl++;
      }

      c_n = ndbl - 3;
    }

    if (c_n + 1 > 0) {
      b_y_data[0] = 2.0;
      if (c_n + 1 > 1) {
        b_y_data[c_n] = apnd;
        i0 = c_n + (c_n < 0);
        if (i0 >= 0) {
          absb = (int32_T)((uint32_T)i0 >> 1);
        } else {
          absb = ~(int32_T)((uint32_T)~i0 >> 1);
        }

        for (ndbl = 1; ndbl < absb; ndbl++) {
          b_y_data[ndbl] = 2.0 + (real_T)ndbl;
          b_y_data[c_n - ndbl] = apnd - ndbl;
        }

        if (absb << 1 == c_n) {
          b_y_data[absb] = (2.0 + (real_T)apnd) / 2.0;
        } else {
          b_y_data[absb] = 2.0 + (real_T)absb;
          b_y_data[absb + 1] = apnd - absb;
        }
      }
    }

    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = (int32_T)emlrtIntegerCheckFastR2012b(b_y_data[i0], &c_emlrtDCI, sp);
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, a_size[0], &ae_emlrtBCI, sp);
    }

    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = (int32_T)y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, a_size[1], &be_emlrtBCI, sp);
    }

    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)b_y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &ce_emlrtBCI, sp);
    }

    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[1];
      i2 = (int32_T)y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &de_emlrtBCI, sp);
    }

    b_size[0] = c_n + 1;
    b_size[1] = n + 1;
    f_fdm_size[0] = c_n + 1;
    f_fdm_size[1] = n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      c_fdm[i0] = b_size[i0];
      b_fdm[i0] = f_fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(c_fdm, b_fdm, &l_emlrtECI, sp);
    b_tmp_size[0] = c_n + 1;
    b_tmp_size[1] = n + 1;
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      apnd = c_n + 1;
      for (i1 = 0; i1 < apnd; i1++) {
        SD->f0.tmp_data[i1 + (c_n + 1) * i0] = SD->f0.b_data[((int32_T)
          b_y_data[i1] + a_size[0] * ((int32_T)y_data[i0] - 1)) - 1] * fdm->
          data[((int32_T)b_y_data[i1] + fdm->size[0] * ((int32_T)y_data[i0] - 1))
          - 1];
      }
    }

    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)b_y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &ee_emlrtBCI, sp);
    }

    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[1];
      i2 = (int32_T)y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &fe_emlrtBCI, sp);
    }

    g_fdm_size[0] = c_n + 1;
    g_fdm_size[1] = n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      iv0[i0] = b_tmp_size[i0];
      b_fdm[i0] = g_fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(iv0, b_fdm, &l_emlrtECI, sp);
    c_tmp_size[0] = c_n + 1;
    c_tmp_size[1] = n + 1;
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      apnd = c_n + 1;
      for (i1 = 0; i1 < apnd; i1++) {
        i2 = (int32_T)b_y_data[i1];
        ez = (int32_T)(y_data[i0] + 1.0);
        SD->f0.b_tmp_data[i1 + (c_n + 1) * i0] = SD->f0.a_data
          [(emlrtDynamicBoundsCheckFastR2012b(i2, 1, a_size[0], &ge_emlrtBCI, sp)
            + a_size[0] * (emlrtDynamicBoundsCheckFastR2012b(ez, 1, a_size[1],
              &he_emlrtBCI, sp) - 1)) - 1];
      }
    }

    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      apnd = c_n + 1;
      for (i1 = 0; i1 < apnd; i1++) {
        i2 = fdm->size[0];
        ez = (int32_T)b_y_data[i1];
        ndbl = fdm->size[1];
        cdiff = (int32_T)(y_data[i0] + 1.0);
        SD->f0.c_tmp_data[i1 + (c_n + 1) * i0] = fdm->data
          [(emlrtDynamicBoundsCheckFastR2012b(ez, 1, i2, &ie_emlrtBCI, sp) +
            fdm->size[0] * (emlrtDynamicBoundsCheckFastR2012b(cdiff, 1, ndbl,
              &je_emlrtBCI, sp) - 1)) - 1];
      }
    }

    b_a_size[0] = c_n + 1;
    b_a_size[1] = n + 1;
    h_fdm_size[0] = c_n + 1;
    h_fdm_size[1] = n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      c_fdm[i0] = b_a_size[i0];
      b_fdm[i0] = h_fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(c_fdm, b_fdm, &m_emlrtECI, sp);
    loop_ub = (c_n + 1) * (n + 1);
    for (i0 = 0; i0 < loop_ub; i0++) {
      SD->f0.b_tmp_data[i0] *= SD->f0.c_tmp_data[i0];
    }

    for (i0 = 0; i0 < 2; i0++) {
      iv0[i0] = b_tmp_size[i0];
      b_fdm[i0] = c_tmp_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(iv0, b_fdm, &l_emlrtECI, sp);
    d_tmp_size[0] = c_n + 1;
    d_tmp_size[1] = n + 1;
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      apnd = c_n + 1;
      for (i1 = 0; i1 < apnd; i1++) {
        i2 = (int32_T)b_y_data[i1];
        ez = (int32_T)(y_data[i0] - 1.0);
        SD->f0.c_tmp_data[i1 + (c_n + 1) * i0] = SD->f0.a_data
          [(emlrtDynamicBoundsCheckFastR2012b(i2, 1, a_size[0], &ke_emlrtBCI, sp)
            + a_size[0] * (emlrtDynamicBoundsCheckFastR2012b(ez, 1, a_size[1],
              &le_emlrtBCI, sp) - 1)) - 1];
      }
    }

    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      apnd = c_n + 1;
      for (i1 = 0; i1 < apnd; i1++) {
        i2 = fdm->size[0];
        ez = (int32_T)b_y_data[i1];
        ndbl = fdm->size[1];
        cdiff = (int32_T)(y_data[i0] - 1.0);
        f_tmp_data[i1 + (c_n + 1) * i0] = fdm->data
          [(emlrtDynamicBoundsCheckFastR2012b(ez, 1, i2, &me_emlrtBCI, sp) +
            fdm->size[0] * (emlrtDynamicBoundsCheckFastR2012b(cdiff, 1, ndbl,
              &ne_emlrtBCI, sp) - 1)) - 1];
      }
    }

    c_a_size[0] = c_n + 1;
    c_a_size[1] = n + 1;
    i_fdm_size[0] = c_n + 1;
    i_fdm_size[1] = n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      c_fdm[i0] = c_a_size[i0];
      b_fdm[i0] = i_fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(c_fdm, b_fdm, &n_emlrtECI, sp);
    loop_ub = (c_n + 1) * (n + 1);
    for (i0 = 0; i0 < loop_ub; i0++) {
      SD->f0.c_tmp_data[i0] *= f_tmp_data[i0];
    }

    for (i0 = 0; i0 < 2; i0++) {
      iv0[i0] = b_tmp_size[i0];
      b_fdm[i0] = d_tmp_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(iv0, b_fdm, &l_emlrtECI, sp);
    e_tmp_size[0] = c_n + 1;
    e_tmp_size[1] = n + 1;
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      apnd = c_n + 1;
      for (i1 = 0; i1 < apnd; i1++) {
        i2 = (int32_T)(b_y_data[i1] + 1.0);
        ez = (int32_T)y_data[i0];
        f_tmp_data[i1 + (c_n + 1) * i0] = SD->f0.a_data
          [(emlrtDynamicBoundsCheckFastR2012b(i2, 1, a_size[0], &oe_emlrtBCI, sp)
            + a_size[0] * (emlrtDynamicBoundsCheckFastR2012b(ez, 1, a_size[1],
              &pe_emlrtBCI, sp) - 1)) - 1];
      }
    }

    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      apnd = c_n + 1;
      for (i1 = 0; i1 < apnd; i1++) {
        i2 = fdm->size[0];
        ez = (int32_T)(b_y_data[i1] + 1.0);
        ndbl = fdm->size[1];
        cdiff = (int32_T)y_data[i0];
        g_tmp_data[i1 + (c_n + 1) * i0] = fdm->data
          [(emlrtDynamicBoundsCheckFastR2012b(ez, 1, i2, &qe_emlrtBCI, sp) +
            fdm->size[0] * (emlrtDynamicBoundsCheckFastR2012b(cdiff, 1, ndbl,
              &re_emlrtBCI, sp) - 1)) - 1];
      }
    }

    d_a_size[0] = c_n + 1;
    d_a_size[1] = n + 1;
    j_fdm_size[0] = c_n + 1;
    j_fdm_size[1] = n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      c_fdm[i0] = d_a_size[i0];
      b_fdm[i0] = j_fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(c_fdm, b_fdm, &o_emlrtECI, sp);
    loop_ub = (c_n + 1) * (n + 1);
    for (i0 = 0; i0 < loop_ub; i0++) {
      f_tmp_data[i0] *= g_tmp_data[i0];
    }

    for (i0 = 0; i0 < 2; i0++) {
      iv0[i0] = b_tmp_size[i0];
      b_fdm[i0] = e_tmp_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(iv0, b_fdm, &l_emlrtECI, sp);
    f_tmp_size[0] = c_n + 1;
    f_tmp_size[1] = n + 1;
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      apnd = c_n + 1;
      for (i1 = 0; i1 < apnd; i1++) {
        i2 = (int32_T)(b_y_data[i1] - 1.0);
        ez = (int32_T)y_data[i0];
        g_tmp_data[i1 + (c_n + 1) * i0] = SD->f0.a_data
          [(emlrtDynamicBoundsCheckFastR2012b(i2, 1, a_size[0], &se_emlrtBCI, sp)
            + a_size[0] * (emlrtDynamicBoundsCheckFastR2012b(ez, 1, a_size[1],
              &te_emlrtBCI, sp) - 1)) - 1];
      }
    }

    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      apnd = c_n + 1;
      for (i1 = 0; i1 < apnd; i1++) {
        i2 = fdm->size[0];
        ez = (int32_T)(b_y_data[i1] - 1.0);
        ndbl = fdm->size[1];
        cdiff = (int32_T)y_data[i0];
        h_tmp_data[i1 + (c_n + 1) * i0] = fdm->data
          [(emlrtDynamicBoundsCheckFastR2012b(ez, 1, i2, &ue_emlrtBCI, sp) +
            fdm->size[0] * (emlrtDynamicBoundsCheckFastR2012b(cdiff, 1, ndbl,
              &ve_emlrtBCI, sp) - 1)) - 1];
      }
    }

    e_a_size[0] = c_n + 1;
    e_a_size[1] = n + 1;
    k_fdm_size[0] = c_n + 1;
    k_fdm_size[1] = n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      c_fdm[i0] = e_a_size[i0];
      b_fdm[i0] = k_fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(c_fdm, b_fdm, &p_emlrtECI, sp);
    loop_ub = (c_n + 1) * (n + 1);
    for (i0 = 0; i0 < loop_ub; i0++) {
      g_tmp_data[i0] *= h_tmp_data[i0];
    }

    for (i0 = 0; i0 < 2; i0++) {
      iv0[i0] = b_tmp_size[i0];
      b_fdm[i0] = f_tmp_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(iv0, b_fdm, &l_emlrtECI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)b_y_data[i0];
      i_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &we_emlrtBCI,
        sp) - 1;
    }

    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[1];
      i2 = (int32_T)y_data[i0];
      e_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &xe_emlrtBCI,
        sp) - 1;
    }

    iv8[0] = c_n + 1;
    iv8[1] = n + 1;
    emlrtSubAssignSizeCheckR2012b(iv8, 2, b_tmp_size, 2, &q_emlrtECI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      apnd = c_n + 1;
      for (i1 = 0; i1 < apnd; i1++) {
        j_tmp_data[i1 + (c_n + 1) * i0] = ((((SD->f0.tmp_data[i1 + (c_n + 1) *
          i0] + fdm->data[(((int32_T)b_y_data[i1] + fdm->size[0] * ((int32_T)
          y_data[i0] - 1)) + fdm->size[0] * fdm->size[1]) - 1]) +
          SD->f0.b_tmp_data[i1 + (c_n + 1) * i0]) + SD->f0.c_tmp_data[i1 + (c_n
          + 1) * i0]) + f_tmp_data[i1 + (c_n + 1) * i0]) + g_tmp_data[i1 + (c_n
          + 1) * i0];
      }
    }

    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      apnd = c_n + 1;
      for (i1 = 0; i1 < apnd; i1++) {
        fdm->data[(i_tmp_data[i1] + fdm->size[0] * e_tmp_data[i0]) + fdm->size[0]
          * fdm->size[1]] = j_tmp_data[i1 + (c_n + 1) * i0];
      }
    }

    /*  time extrapolation at iz = 1 */
    emlrtDynamicBoundsCheckFastR2012b(1, 1, a_size[0], &s_emlrtBCI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = (int32_T)y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, a_size[1], &ye_emlrtBCI, sp);
    }

    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &t_emlrtBCI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[1];
      i2 = (int32_T)y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &af_emlrtBCI, sp);
    }

    b_b_size[0] = 1;
    b_b_size[1] = n + 1;
    l_fdm_size[0] = 1;
    l_fdm_size[1] = n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      c_fdm[i0] = b_b_size[i0];
      b_fdm[i0] = l_fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(c_fdm, b_fdm, &r_emlrtECI, sp);
    g_tmp_size[0] = 1;
    g_tmp_size[1] = n + 1;
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      k_tmp_data[i0] = SD->f0.b_data[a_size[0] * ((int32_T)y_data[i0] - 1)] *
        fdm->data[fdm->size[0] * ((int32_T)y_data[i0] - 1)];
    }

    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &u_emlrtBCI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[1];
      i2 = (int32_T)y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &bf_emlrtBCI, sp);
    }

    m_fdm_size[0] = 1;
    m_fdm_size[1] = n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      iv0[i0] = g_tmp_size[i0];
      b_fdm[i0] = m_fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(iv0, b_fdm, &r_emlrtECI, sp);
    emlrtDynamicBoundsCheckFastR2012b(1, 1, a_size[0], &v_emlrtBCI, sp);
    h_tmp_size[1] = n + 1;
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = (int32_T)(y_data[i0] + 1.0);
      l_tmp_data[i0] = SD->f0.a_data[a_size[0] *
        (emlrtDynamicBoundsCheckFastR2012b(i1, 1, a_size[1], &cf_emlrtBCI, sp) -
         1)];
    }

    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &w_emlrtBCI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[1];
      i2 = (int32_T)(y_data[i0] + 1.0);
      m_tmp_data[i0] = fdm->data[fdm->size[0] *
        (emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &df_emlrtBCI, sp) - 1)];
    }

    f_a_size[0] = 1;
    f_a_size[1] = n + 1;
    n_fdm_size[0] = 1;
    n_fdm_size[1] = n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      c_fdm[i0] = f_a_size[i0];
      b_fdm[i0] = n_fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(c_fdm, b_fdm, &s_emlrtECI, sp);
    h_tmp_size[0] = 1;
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      l_tmp_data[i0] *= m_tmp_data[i0];
    }

    for (i0 = 0; i0 < 2; i0++) {
      iv0[i0] = g_tmp_size[i0];
      b_fdm[i0] = h_tmp_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(iv0, b_fdm, &r_emlrtECI, sp);
    emlrtDynamicBoundsCheckFastR2012b(1, 1, a_size[0], &x_emlrtBCI, sp);
    i_tmp_size[1] = n + 1;
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = (int32_T)(y_data[i0] - 1.0);
      m_tmp_data[i0] = SD->f0.a_data[a_size[0] *
        (emlrtDynamicBoundsCheckFastR2012b(i1, 1, a_size[1], &ef_emlrtBCI, sp) -
         1)];
    }

    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &y_emlrtBCI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[1];
      i2 = (int32_T)(y_data[i0] - 1.0);
      n_tmp_data[i0] = fdm->data[fdm->size[0] *
        (emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &ff_emlrtBCI, sp) - 1)];
    }

    g_a_size[0] = 1;
    g_a_size[1] = n + 1;
    o_fdm_size[0] = 1;
    o_fdm_size[1] = n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      c_fdm[i0] = g_a_size[i0];
      b_fdm[i0] = o_fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(c_fdm, b_fdm, &t_emlrtECI, sp);
    i_tmp_size[0] = 1;
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      m_tmp_data[i0] *= n_tmp_data[i0];
    }

    for (i0 = 0; i0 < 2; i0++) {
      iv0[i0] = g_tmp_size[i0];
      b_fdm[i0] = i_tmp_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(iv0, b_fdm, &r_emlrtECI, sp);
    emlrtDynamicBoundsCheckFastR2012b(2, 1, a_size[0], &ab_emlrtBCI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = (int32_T)y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, a_size[1], &gf_emlrtBCI, sp);
    }

    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(2, 1, i0, &bb_emlrtBCI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[1];
      i2 = (int32_T)y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &hf_emlrtBCI, sp);
    }

    h_a_size[0] = 1;
    h_a_size[1] = n + 1;
    p_fdm_size[0] = 1;
    p_fdm_size[1] = n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      c_fdm[i0] = h_a_size[i0];
      b_fdm[i0] = p_fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(c_fdm, b_fdm, &u_emlrtECI, sp);
    j_tmp_size[0] = 1;
    j_tmp_size[1] = n + 1;
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      n_tmp_data[i0] = SD->f0.a_data[1 + a_size[0] * ((int32_T)y_data[i0] - 1)] *
        fdm->data[1 + fdm->size[0] * ((int32_T)y_data[i0] - 1)];
    }

    for (i0 = 0; i0 < 2; i0++) {
      iv0[i0] = g_tmp_size[i0];
      b_fdm[i0] = j_tmp_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(iv0, b_fdm, &r_emlrtECI, sp);
    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &cb_emlrtBCI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[1];
      i2 = (int32_T)y_data[i0];
      e_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &if_emlrtBCI,
        sp) - 1;
    }

    iv9[0] = 1;
    iv9[1] = n + 1;
    emlrtSubAssignSizeCheckR2012b(iv9, 2, g_tmp_size, 2, &v_emlrtECI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      o_tmp_data[i0] = (((k_tmp_data[i0] + fdm->data[fdm->size[0] * ((int32_T)
        y_data[i0] - 1) + fdm->size[0] * fdm->size[1]]) + l_tmp_data[i0]) +
                        m_tmp_data[i0]) + n_tmp_data[i0];
    }

    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      fdm->data[fdm->size[0] * e_tmp_data[i0] + fdm->size[0] * fdm->size[1]] =
        o_tmp_data[i0];
    }

    if (bz == v_size[0]) {
      /*  time extrapolation at iz = nz */
      i0 = v_size[0];
      emlrtDynamicBoundsCheckFastR2012b(i0, 1, a_size[0], &db_emlrtBCI, sp);
      loop_ub = n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        i1 = (int32_T)y_data[i0];
        emlrtDynamicBoundsCheckFastR2012b(i1, 1, a_size[1], &jf_emlrtBCI, sp);
      }

      i0 = fdm->size[0];
      i1 = v_size[0];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &eb_emlrtBCI, sp);
      loop_ub = n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        i1 = fdm->size[1];
        i2 = (int32_T)y_data[i0];
        emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &kf_emlrtBCI, sp);
      }

      c_b_size[0] = 1;
      c_b_size[1] = n + 1;
      q_fdm_size[0] = 1;
      q_fdm_size[1] = n + 1;
      for (i0 = 0; i0 < 2; i0++) {
        c_fdm[i0] = c_b_size[i0];
        b_fdm[i0] = q_fdm_size[i0];
      }

      emlrtSizeEqCheck2DFastR2012b(c_fdm, b_fdm, &w_emlrtECI, sp);
      g_tmp_size[0] = 1;
      g_tmp_size[1] = n + 1;
      loop_ub = n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        k_tmp_data[i0] = SD->f0.b_data[(v_size[0] + a_size[0] * ((int32_T)
          y_data[i0] - 1)) - 1] * fdm->data[(v_size[0] + fdm->size[0] *
          ((int32_T)y_data[i0] - 1)) - 1];
      }

      i0 = fdm->size[0];
      i1 = v_size[0];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &fb_emlrtBCI, sp);
      loop_ub = n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        i1 = fdm->size[1];
        i2 = (int32_T)y_data[i0];
        emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &lf_emlrtBCI, sp);
      }

      r_fdm_size[0] = 1;
      r_fdm_size[1] = n + 1;
      for (i0 = 0; i0 < 2; i0++) {
        iv0[i0] = g_tmp_size[i0];
        b_fdm[i0] = r_fdm_size[i0];
      }

      emlrtSizeEqCheck2DFastR2012b(iv0, b_fdm, &w_emlrtECI, sp);
      emlrtDynamicBoundsCheckFastR2012b(v_size[0], 1, a_size[0], &gb_emlrtBCI,
        sp);
      h_tmp_size[1] = n + 1;
      loop_ub = n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        i1 = (int32_T)(y_data[i0] + 1.0);
        l_tmp_data[i0] = SD->f0.a_data[(v_size[0] + a_size[0] *
          (emlrtDynamicBoundsCheckFastR2012b(i1, 1, a_size[1], &mf_emlrtBCI, sp)
           - 1)) - 1];
      }

      i0 = fdm->size[0];
      absb = emlrtDynamicBoundsCheckFastR2012b(v_size[0], 1, i0, &hb_emlrtBCI,
        sp);
      loop_ub = n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        i1 = fdm->size[1];
        i2 = (int32_T)(y_data[i0] + 1.0);
        m_tmp_data[i0] = fdm->data[(absb + fdm->size[0] *
          (emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &nf_emlrtBCI, sp) - 1))
          - 1];
      }

      i_a_size[0] = 1;
      i_a_size[1] = n + 1;
      s_fdm_size[0] = 1;
      s_fdm_size[1] = n + 1;
      for (i0 = 0; i0 < 2; i0++) {
        c_fdm[i0] = i_a_size[i0];
        b_fdm[i0] = s_fdm_size[i0];
      }

      emlrtSizeEqCheck2DFastR2012b(c_fdm, b_fdm, &x_emlrtECI, sp);
      h_tmp_size[0] = 1;
      loop_ub = n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        l_tmp_data[i0] *= m_tmp_data[i0];
      }

      for (i0 = 0; i0 < 2; i0++) {
        iv0[i0] = g_tmp_size[i0];
        b_fdm[i0] = h_tmp_size[i0];
      }

      emlrtSizeEqCheck2DFastR2012b(iv0, b_fdm, &w_emlrtECI, sp);
      emlrtDynamicBoundsCheckFastR2012b(v_size[0], 1, a_size[0], &ib_emlrtBCI,
        sp);
      i_tmp_size[1] = n + 1;
      loop_ub = n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        i1 = (int32_T)(y_data[i0] - 1.0);
        m_tmp_data[i0] = SD->f0.a_data[(v_size[0] + a_size[0] *
          (emlrtDynamicBoundsCheckFastR2012b(i1, 1, a_size[1], &of_emlrtBCI, sp)
           - 1)) - 1];
      }

      i0 = fdm->size[0];
      absb = emlrtDynamicBoundsCheckFastR2012b(v_size[0], 1, i0, &jb_emlrtBCI,
        sp);
      loop_ub = n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        i1 = fdm->size[1];
        i2 = (int32_T)(y_data[i0] - 1.0);
        n_tmp_data[i0] = fdm->data[(absb + fdm->size[0] *
          (emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &pf_emlrtBCI, sp) - 1))
          - 1];
      }

      j_a_size[0] = 1;
      j_a_size[1] = n + 1;
      t_fdm_size[0] = 1;
      t_fdm_size[1] = n + 1;
      for (i0 = 0; i0 < 2; i0++) {
        c_fdm[i0] = j_a_size[i0];
        b_fdm[i0] = t_fdm_size[i0];
      }

      emlrtSizeEqCheck2DFastR2012b(c_fdm, b_fdm, &y_emlrtECI, sp);
      i_tmp_size[0] = 1;
      loop_ub = n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        m_tmp_data[i0] *= n_tmp_data[i0];
      }

      for (i0 = 0; i0 < 2; i0++) {
        iv0[i0] = g_tmp_size[i0];
        b_fdm[i0] = i_tmp_size[i0];
      }

      emlrtSizeEqCheck2DFastR2012b(iv0, b_fdm, &w_emlrtECI, sp);
      i0 = (int32_T)((real_T)v_size[0] - 1.0);
      emlrtDynamicBoundsCheckFastR2012b(i0, 1, a_size[0], &kb_emlrtBCI, sp);
      loop_ub = n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        i1 = (int32_T)y_data[i0];
        emlrtDynamicBoundsCheckFastR2012b(i1, 1, a_size[1], &qf_emlrtBCI, sp);
      }

      i0 = fdm->size[0];
      i1 = (int32_T)((real_T)v_size[0] - 1.0);
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &lb_emlrtBCI, sp);
      loop_ub = n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        i1 = fdm->size[1];
        i2 = (int32_T)y_data[i0];
        emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &rf_emlrtBCI, sp);
      }

      k_a_size[0] = 1;
      k_a_size[1] = n + 1;
      u_fdm_size[0] = 1;
      u_fdm_size[1] = n + 1;
      for (i0 = 0; i0 < 2; i0++) {
        c_fdm[i0] = k_a_size[i0];
        b_fdm[i0] = u_fdm_size[i0];
      }

      emlrtSizeEqCheck2DFastR2012b(c_fdm, b_fdm, &ab_emlrtECI, sp);
      j_tmp_size[0] = 1;
      j_tmp_size[1] = n + 1;
      loop_ub = n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        n_tmp_data[i0] = SD->f0.a_data[(v_size[0] + a_size[0] * ((int32_T)
          y_data[i0] - 1)) - 2] * fdm->data[(v_size[0] + fdm->size[0] *
          ((int32_T)y_data[i0] - 1)) - 2];
      }

      for (i0 = 0; i0 < 2; i0++) {
        iv0[i0] = g_tmp_size[i0];
        b_fdm[i0] = j_tmp_size[i0];
      }

      emlrtSizeEqCheck2DFastR2012b(iv0, b_fdm, &w_emlrtECI, sp);
      i0 = fdm->size[0];
      i1 = v_size[0];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &mb_emlrtBCI, sp);
      loop_ub = n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        i1 = fdm->size[1];
        i2 = (int32_T)y_data[i0];
        e_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
          &sf_emlrtBCI, sp) - 1;
      }

      iv10[0] = 1;
      iv10[1] = n + 1;
      emlrtSubAssignSizeCheckR2012b(iv10, 2, g_tmp_size, 2, &bb_emlrtECI, sp);
      loop_ub = n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        o_tmp_data[i0] = (((k_tmp_data[i0] + fdm->data[((v_size[0] + fdm->size[0]
          * ((int32_T)y_data[i0] - 1)) + fdm->size[0] * fdm->size[1]) - 1]) +
                           l_tmp_data[i0]) + m_tmp_data[i0]) + n_tmp_data[i0];
      }

      loop_ub = n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        fdm->data[((v_size[0] + fdm->size[0] * e_tmp_data[i0]) + fdm->size[0] *
                   fdm->size[1]) - 1] = o_tmp_data[i0];
      }

      /*  time extrapolation at corner (nz,1) */
      i0 = fdm->size[1];
      emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &ub_emlrtBCI, sp);
      emlrtDynamicBoundsCheckFastR2012b(1, 1, a_size[1], &nb_emlrtBCI, sp);
      i0 = fdm->size[1];
      emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &ob_emlrtBCI, sp);
      i0 = fdm->size[1];
      emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &pb_emlrtBCI, sp);
      emlrtDynamicBoundsCheckFastR2012b(2, 1, a_size[1], &qb_emlrtBCI, sp);
      i0 = fdm->size[1];
      emlrtDynamicBoundsCheckFastR2012b(2, 1, i0, &rb_emlrtBCI, sp);
      emlrtDynamicBoundsCheckFastR2012b(1, 1, a_size[1], &sb_emlrtBCI, sp);
      i0 = fdm->size[1];
      emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &tb_emlrtBCI, sp);
      i0 = fdm->size[0];
      i1 = fdm->size[0];
      i2 = fdm->size[0];
      ez = fdm->size[0];
      ndbl = v_size[0] - 1;
      cdiff = fdm->size[0];
      absb = v_size[0] - 1;
      fdm->data[(emlrtDynamicBoundsCheckFastR2012b(v_size[0], 1, i0,
                  &tf_emlrtBCI, sp) + fdm->size[0] * fdm->size[1]) - 1] =
        ((SD->f0.b_data[emlrtDynamicBoundsCheckFastR2012b(v_size[0], 1, a_size[0],
           &uf_emlrtBCI, sp) - 1] * fdm->data[emlrtDynamicBoundsCheckFastR2012b
          (v_size[0], 1, i1, &vf_emlrtBCI, sp) - 1] + fdm->data
          [(emlrtDynamicBoundsCheckFastR2012b(v_size[0], 1, i2, &wf_emlrtBCI, sp)
            + fdm->size[0] * fdm->size[1]) - 1]) + SD->f0.a_data
         [(emlrtDynamicBoundsCheckFastR2012b(v_size[0], 1, a_size[0],
           &xf_emlrtBCI, sp) + a_size[0]) - 1] * fdm->data
         [(emlrtDynamicBoundsCheckFastR2012b(v_size[0], 1, ez, &yf_emlrtBCI, sp)
           + fdm->size[0]) - 1]) + SD->
        f0.a_data[emlrtDynamicBoundsCheckFastR2012b(ndbl, 1, a_size[0],
        &ag_emlrtBCI, sp) - 1] * fdm->data[emlrtDynamicBoundsCheckFastR2012b
        (absb, 1, cdiff, &bg_emlrtBCI, sp) - 1];
    }

    emlrtDynamicBoundsCheckFastR2012b(1, 1, a_size[1], &vb_emlrtBCI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = (int32_T)b_y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, a_size[0], &cg_emlrtBCI, sp);
    }

    i0 = fdm->size[1];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &wb_emlrtBCI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)b_y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &dg_emlrtBCI, sp);
    }

    emlrtSizeEqCheck1DFastR2012b(c_n + 1, c_n + 1, &cb_emlrtECI, sp);
    k_tmp_size[0] = c_n + 1;
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      p_tmp_data[i0] = SD->f0.b_data[(int32_T)b_y_data[i0] - 1] * fdm->data
        [(int32_T)b_y_data[i0] - 1];
    }

    i0 = fdm->size[1];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &xb_emlrtBCI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)b_y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &eg_emlrtBCI, sp);
    }

    emlrtSizeEqCheck1DFastR2012b(c_n + 1, c_n + 1, &cb_emlrtECI, sp);
    emlrtDynamicBoundsCheckFastR2012b(2, 1, a_size[1], &yb_emlrtBCI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = (int32_T)b_y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, a_size[0], &fg_emlrtBCI, sp);
    }

    i0 = fdm->size[1];
    emlrtDynamicBoundsCheckFastR2012b(2, 1, i0, &ac_emlrtBCI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)b_y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &gg_emlrtBCI, sp);
    }

    emlrtSizeEqCheck1DFastR2012b(c_n + 1, c_n + 1, &db_emlrtECI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      q_tmp_data[i0] = SD->f0.a_data[((int32_T)b_y_data[i0] + a_size[0]) - 1] *
        fdm->data[((int32_T)b_y_data[i0] + fdm->size[0]) - 1];
    }

    emlrtSizeEqCheck1DFastR2012b(c_n + 1, c_n + 1, &cb_emlrtECI, sp);
    emlrtDynamicBoundsCheckFastR2012b(1, 1, a_size[1], &bc_emlrtBCI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = (int32_T)(b_y_data[i0] + 1.0);
      r_tmp_data[i0] = SD->f0.a_data[emlrtDynamicBoundsCheckFastR2012b(i1, 1,
        a_size[0], &hg_emlrtBCI, sp) - 1];
    }

    i0 = fdm->size[1];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &cc_emlrtBCI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)(b_y_data[i0] + 1.0);
      s_tmp_data[i0] = fdm->data[emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
        &ig_emlrtBCI, sp) - 1];
    }

    emlrtSizeEqCheck1DFastR2012b(c_n + 1, c_n + 1, &eb_emlrtECI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      r_tmp_data[i0] *= s_tmp_data[i0];
    }

    emlrtSizeEqCheck1DFastR2012b(c_n + 1, c_n + 1, &cb_emlrtECI, sp);
    emlrtDynamicBoundsCheckFastR2012b(1, 1, a_size[1], &dc_emlrtBCI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = (int32_T)(b_y_data[i0] - 1.0);
      s_tmp_data[i0] = SD->f0.a_data[emlrtDynamicBoundsCheckFastR2012b(i1, 1,
        a_size[0], &jg_emlrtBCI, sp) - 1];
    }

    i0 = fdm->size[1];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &ec_emlrtBCI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)(b_y_data[i0] - 1.0);
      t_tmp_data[i0] = fdm->data[emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
        &kg_emlrtBCI, sp) - 1];
    }

    emlrtSizeEqCheck1DFastR2012b(c_n + 1, c_n + 1, &fb_emlrtECI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      s_tmp_data[i0] *= t_tmp_data[i0];
    }

    emlrtSizeEqCheck1DFastR2012b(c_n + 1, c_n + 1, &cb_emlrtECI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)b_y_data[i0];
      i_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &lg_emlrtBCI,
        sp) - 1;
    }

    i0 = fdm->size[1];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &fc_emlrtBCI, sp);
    iv11[0] = c_n + 1;
    emlrtSubAssignSizeCheckR2012b(iv11, 1, k_tmp_size, 1, &gb_emlrtECI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      u_tmp_data[i0] = (((p_tmp_data[i0] + fdm->data[((int32_T)b_y_data[i0] +
        fdm->size[0] * fdm->size[1]) - 1]) + q_tmp_data[i0]) + r_tmp_data[i0]) +
        s_tmp_data[i0];
    }

    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      fdm->data[i_tmp_data[i0] + fdm->size[0] * fdm->size[1]] = u_tmp_data[i0];
    }

    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = (int32_T)b_y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, a_size[0], &mg_emlrtBCI, sp);
    }

    i0 = v_size[1];
    emlrtDynamicBoundsCheckFastR2012b(i0, 1, a_size[1], &gc_emlrtBCI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)b_y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &ng_emlrtBCI, sp);
    }

    i0 = fdm->size[1];
    i1 = v_size[1];
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &hc_emlrtBCI, sp);
    emlrtSizeEqCheck1DFastR2012b(c_n + 1, c_n + 1, &hb_emlrtECI, sp);
    k_tmp_size[0] = c_n + 1;
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      p_tmp_data[i0] = SD->f0.b_data[((int32_T)b_y_data[i0] + a_size[0] *
        (v_size[1] - 1)) - 1] * fdm->data[((int32_T)b_y_data[i0] + fdm->size[0] *
        (v_size[1] - 1)) - 1];
    }

    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)b_y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &og_emlrtBCI, sp);
    }

    i0 = fdm->size[1];
    i1 = v_size[1];
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &ic_emlrtBCI, sp);
    emlrtSizeEqCheck1DFastR2012b(c_n + 1, c_n + 1, &hb_emlrtECI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = (int32_T)b_y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, a_size[0], &pg_emlrtBCI, sp);
    }

    i0 = (int32_T)((real_T)v_size[1] - 1.0);
    emlrtDynamicBoundsCheckFastR2012b(i0, 1, a_size[1], &jc_emlrtBCI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)b_y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &qg_emlrtBCI, sp);
    }

    i0 = fdm->size[1];
    i1 = (int32_T)((real_T)v_size[1] - 1.0);
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &kc_emlrtBCI, sp);
    emlrtSizeEqCheck1DFastR2012b(c_n + 1, c_n + 1, &ib_emlrtECI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      q_tmp_data[i0] = SD->f0.a_data[((int32_T)b_y_data[i0] + a_size[0] *
        (v_size[1] - 2)) - 1] * fdm->data[((int32_T)b_y_data[i0] + fdm->size[0] *
        (v_size[1] - 2)) - 1];
    }

    emlrtSizeEqCheck1DFastR2012b(c_n + 1, c_n + 1, &hb_emlrtECI, sp);
    emlrtDynamicBoundsCheckFastR2012b(v_size[1], 1, a_size[1], &lc_emlrtBCI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = (int32_T)(b_y_data[i0] + 1.0);
      r_tmp_data[i0] = SD->f0.a_data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1,
        a_size[0], &rg_emlrtBCI, sp) + a_size[0] * (v_size[1] - 1)) - 1];
    }

    i0 = fdm->size[1];
    absb = emlrtDynamicBoundsCheckFastR2012b(v_size[1], 1, i0, &mc_emlrtBCI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)(b_y_data[i0] + 1.0);
      s_tmp_data[i0] = fdm->data[(emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
        &sg_emlrtBCI, sp) + fdm->size[0] * (absb - 1)) - 1];
    }

    emlrtSizeEqCheck1DFastR2012b(c_n + 1, c_n + 1, &jb_emlrtECI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      r_tmp_data[i0] *= s_tmp_data[i0];
    }

    emlrtSizeEqCheck1DFastR2012b(c_n + 1, c_n + 1, &hb_emlrtECI, sp);
    emlrtDynamicBoundsCheckFastR2012b(v_size[1], 1, a_size[1], &nc_emlrtBCI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = (int32_T)(b_y_data[i0] - 1.0);
      s_tmp_data[i0] = SD->f0.a_data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1,
        a_size[0], &tg_emlrtBCI, sp) + a_size[0] * (v_size[1] - 1)) - 1];
    }

    i0 = fdm->size[1];
    absb = emlrtDynamicBoundsCheckFastR2012b(v_size[1], 1, i0, &oc_emlrtBCI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)(b_y_data[i0] - 1.0);
      t_tmp_data[i0] = fdm->data[(emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
        &ug_emlrtBCI, sp) + fdm->size[0] * (absb - 1)) - 1];
    }

    emlrtSizeEqCheck1DFastR2012b(c_n + 1, c_n + 1, &kb_emlrtECI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      s_tmp_data[i0] *= t_tmp_data[i0];
    }

    emlrtSizeEqCheck1DFastR2012b(c_n + 1, c_n + 1, &hb_emlrtECI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)b_y_data[i0];
      i_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &vg_emlrtBCI,
        sp) - 1;
    }

    i0 = fdm->size[1];
    i1 = v_size[1];
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &pc_emlrtBCI, sp);
    iv12[0] = c_n + 1;
    emlrtSubAssignSizeCheckR2012b(iv12, 1, k_tmp_size, 1, &lb_emlrtECI, sp);
    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      u_tmp_data[i0] = (((p_tmp_data[i0] + fdm->data[(((int32_T)b_y_data[i0] +
        fdm->size[0] * (v_size[1] - 1)) + fdm->size[0] * fdm->size[1]) - 1]) +
                         q_tmp_data[i0]) + r_tmp_data[i0]) + s_tmp_data[i0];
    }

    loop_ub = c_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      fdm->data[(i_tmp_data[i0] + fdm->size[0] * (v_size[1] - 1)) + fdm->size[0]
        * fdm->size[1]] = u_tmp_data[i0];
    }

    /*  time extrapolation at corner (1,1) */
    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &fd_emlrtBCI, sp);
    i0 = fdm->size[1];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &gd_emlrtBCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(1, 1, a_size[0], &qc_emlrtBCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(1, 1, a_size[1], &rc_emlrtBCI, sp);
    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &sc_emlrtBCI, sp);
    i0 = fdm->size[1];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &tc_emlrtBCI, sp);
    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &uc_emlrtBCI, sp);
    i0 = fdm->size[1];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &vc_emlrtBCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(1, 1, a_size[0], &wc_emlrtBCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(2, 1, a_size[1], &xc_emlrtBCI, sp);
    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &yc_emlrtBCI, sp);
    i0 = fdm->size[1];
    emlrtDynamicBoundsCheckFastR2012b(2, 1, i0, &ad_emlrtBCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(2, 1, a_size[0], &bd_emlrtBCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(1, 1, a_size[1], &cd_emlrtBCI, sp);
    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(2, 1, i0, &dd_emlrtBCI, sp);
    i0 = fdm->size[1];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &ed_emlrtBCI, sp);
    fdm->data[fdm->size[0] * fdm->size[1]] = ((SD->f0.b_data[0] * fdm->data[0] +
      fdm->data[fdm->size[0] * fdm->size[1]]) + SD->f0.a_data[a_size[0]] *
      fdm->data[fdm->size[0]]) + SD->f0.a_data[1] * fdm->data[1];

    /*  time extrapolation at corner (1,nx) */
    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &od_emlrtBCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(1, 1, a_size[0], &hd_emlrtBCI, sp);
    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &id_emlrtBCI, sp);
    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &jd_emlrtBCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(1, 1, a_size[0], &kd_emlrtBCI, sp);
    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &ld_emlrtBCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(2, 1, a_size[0], &md_emlrtBCI, sp);
    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(2, 1, i0, &nd_emlrtBCI, sp);
    i0 = fdm->size[1];
    i1 = fdm->size[1];
    i2 = fdm->size[1];
    ez = v_size[1] - 1;
    ndbl = fdm->size[1];
    cdiff = v_size[1] - 1;
    absb = fdm->size[1];
    fdm->data[fdm->size[0] * (emlrtDynamicBoundsCheckFastR2012b(v_size[1], 1, i0,
      &wg_emlrtBCI, sp) - 1) + fdm->size[0] * fdm->size[1]] = ((SD->
      f0.b_data[a_size[0] * (emlrtDynamicBoundsCheckFastR2012b(v_size[1], 1,
      a_size[1], &xg_emlrtBCI, sp) - 1)] * fdm->data[fdm->size[0] *
      (emlrtDynamicBoundsCheckFastR2012b(v_size[1], 1, i1, &yg_emlrtBCI, sp) - 1)]
      + fdm->data[fdm->size[0] * (emlrtDynamicBoundsCheckFastR2012b(v_size[1], 1,
      i2, &ah_emlrtBCI, sp) - 1) + fdm->size[0] * fdm->size[1]]) + SD->
      f0.a_data[a_size[0] * (emlrtDynamicBoundsCheckFastR2012b(ez, 1, a_size[1],
      &bh_emlrtBCI, sp) - 1)] * fdm->data[fdm->size[0] *
      (emlrtDynamicBoundsCheckFastR2012b(cdiff, 1, ndbl, &ch_emlrtBCI, sp) - 1)])
      + SD->f0.a_data[1 + a_size[0] * (emlrtDynamicBoundsCheckFastR2012b(v_size
      [1], 1, a_size[1], &dh_emlrtBCI, sp) - 1)] * fdm->data[1 + fdm->size[0] *
      (emlrtDynamicBoundsCheckFastR2012b(v_size[1], 1, absb, &eh_emlrtBCI, sp) -
       1)];

    /*  set up fdm for next iteration */
    loop_ub = fdm->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      d_tmp_data[i0] = i0;
    }

    apnd = fdm->size[1];
    for (i0 = 0; i0 < apnd; i0++) {
      tmp_data[i0] = i0;
    }

    iv13[0] = loop_ub;
    iv13[1] = apnd;
    i0 = fdm->size[0];
    i1 = fdm->size[1];
    v_fdm_size[0] = i0;
    v_fdm_size[1] = i1;
    for (i0 = 0; i0 < 2; i0++) {
      b_fdm[i0] = v_fdm_size[i0];
    }

    emlrtSubAssignSizeCheckR2012b(iv13, 2, b_fdm, 2, &mb_emlrtECI, sp);
    absb = fdm->size[0];
    ez = fdm->size[1];
    for (i0 = 0; i0 < ez; i0++) {
      for (i1 = 0; i1 < absb; i1++) {
        SD->f0.v_data[i1 + absb * i0] = fdm->data[(i1 + fdm->size[0] * i0) +
          fdm->size[0] * fdm->size[1]];
      }
    }

    for (i0 = 0; i0 < ez; i0++) {
      for (i1 = 0; i1 < absb; i1++) {
        fdm->data[d_tmp_data[i1] + fdm->size[0] * tmp_data[i0]] = SD->
          f0.v_data[i1 + absb * i0];
      }
    }

    loop_ub = fdm->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      d_tmp_data[i0] = i0;
    }

    apnd = fdm->size[1];
    for (i0 = 0; i0 < apnd; i0++) {
      tmp_data[i0] = i0;
    }

    iv14[0] = loop_ub;
    iv14[1] = apnd;
    i0 = fdm->size[0];
    i1 = fdm->size[1];
    w_fdm_size[0] = i0;
    w_fdm_size[1] = i1;
    for (i0 = 0; i0 < 2; i0++) {
      b_fdm[i0] = w_fdm_size[i0];
    }

    emlrtSubAssignSizeCheckR2012b(iv14, 2, b_fdm, 2, &nb_emlrtECI, sp);
    absb = fdm->size[0];
    ez = fdm->size[1];
    for (i0 = 0; i0 < ez; i0++) {
      for (i1 = 0; i1 < absb; i1++) {
        SD->f0.v_data[i1 + absb * i0] = fdm->data[(i1 + fdm->size[0] * i0) +
          (fdm->size[0] * fdm->size[1] << 1)];
      }
    }

    for (i0 = 0; i0 < ez; i0++) {
      for (i1 = 0; i1 < absb; i1++) {
        fdm->data[(d_tmp_data[i1] + fdm->size[0] * tmp_data[i0]) + fdm->size[0] *
          fdm->size[1]] = SD->f0.v_data[i1 + absb * i0];
      }
    }

    /*  insert surface boundary wavefield */
    if (b_it > 2) {
      if (2 > v_size[0]) {
        i0 = 0;
        i1 = 1;
      } else {
        i0 = fdm->size[0];
        emlrtDynamicBoundsCheckFastR2012b(2, 1, i0, &pd_emlrtBCI, sp);
        i0 = 1;
        i1 = fdm->size[0];
        i1 = emlrtDynamicBoundsCheckFastR2012b(v_size[0], 1, i1, &pd_emlrtBCI,
          sp) + 1;
      }

      loop_ub = fdm->size[1];
      absb = (i1 - i0) - 1;
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (i2 = 0; i2 < absb; i2++) {
          fdm->data[((i0 + i2) + fdm->size[0] * i1) + (fdm->size[0] * fdm->size
            [1] << 1)] = 0.0;
        }
      }

      i0 = fdm->size[0];
      emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &rd_emlrtBCI, sp);
      loop_ub = fdm->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        tmp_data[i0] = i0;
      }

      i0 = data->size[1];
      i1 = b_it - 2;
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &qd_emlrtBCI, sp);
      iv15[0] = 1;
      iv15[1] = loop_ub;
      i0 = data->size[0];
      e_data[0] = i0;
      emlrtSubAssignSizeCheckR2012b(iv15, 2, e_data, 1, &ob_emlrtECI, sp);
      apnd = data->size[0];
      for (i0 = 0; i0 < apnd; i0++) {
        data_data[i0] = data->data[i0 + data->size[0] * (b_it - 3)];
      }

      for (i0 = 0; i0 < loop_ub; i0++) {
        fdm->data[fdm->size[0] * tmp_data[i0] + (fdm->size[0] * fdm->size[1] <<
          1)] = data_data[i0];
      }
    }

    /*     %{ */
    /*     figure(3), imagesc(diff(fdm(:,:,1),2,1)) */
    /*     title(['Iteration: ',num2str(it)]) */
    /*     colormap gray */
    /*     %caxis([-2 2]) */
    /*     drawnow */
    /*     if it < 12800 */
    /*         disp('checking') */
    /*     end */
    /*     %} */
    loop_ub = snapshot->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      d_tmp_data[i0] = i0;
    }

    apnd = snapshot->size[1];
    for (i0 = 0; i0 < apnd; i0++) {
      tmp_data[i0] = i0;
    }

    i0 = snapshot->size[2];
    emlrtDynamicBoundsCheckFastR2012b(b_it, 1, i0, &sd_emlrtBCI, sp);
    iv16[0] = loop_ub;
    iv16[1] = apnd;
    i0 = fdm->size[0];
    i1 = fdm->size[1];
    x_fdm_size[0] = i0;
    x_fdm_size[1] = i1;
    for (i0 = 0; i0 < 2; i0++) {
      b_fdm[i0] = x_fdm_size[i0];
    }

    emlrtSubAssignSizeCheckR2012b(iv16, 2, b_fdm, 2, &pb_emlrtECI, sp);
    loop_ub = fdm->size[0] - 1;
    apnd = fdm->size[1] - 1;
    for (i0 = 0; i0 <= apnd; i0++) {
      for (i1 = 0; i1 <= loop_ub; i1++) {
        snapshot->data[(d_tmp_data[i1] + snapshot->size[0] * tmp_data[i0]) +
          snapshot->size[0] * snapshot->size[1] * (b_it - 1)] = fdm->data[i1 +
          fdm->size[0] * i0];
      }
    }

    it++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
  }

  /*  time loop */
  /*  write out final wavefield */
  loop_ub = fdm->size[0];
  apnd = fdm->size[1];
  model_size[0] = loop_ub;
  model_size[1] = apnd;
  for (i0 = 0; i0 < apnd; i0++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      model_data[i1 + model_size[0] * i0] = fdm->data[i1 + fdm->size[0] * i0];
    }
  }

  emxFree_real_T(&fdm);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (rtm2d.c) */
