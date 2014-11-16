/*
 * fm2d.c
 *
 * Code generation for function 'fm2d'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fm2d.h"
#include "fm2d_emxutil.h"
#include "power.h"
#include "fm2d_data.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 1, 28, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtRTEInfo b_emlrtRTEI = { 32, 1, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtBCInfo emlrtBCI = { -1, -1, 41, 20, "model", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtRTEInfo d_emlrtRTEI = { 54, 1, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtECInfo emlrtECI = { -1, 40, 1, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtECInfo b_emlrtECI = { 2, 56, 20, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtECInfo c_emlrtECI = { 2, 57, 20, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtECInfo d_emlrtECI = { 2, 57, 9, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtECInfo e_emlrtECI = { -1, 56, 5, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 61, 24, "b", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 61, 35, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtECInfo f_emlrtECI = { -1, 61, 19, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 61, 49, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 62, 14, "a", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 62, 26, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 62, 42, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtECInfo g_emlrtECI = { -1, 62, 19, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 62, 58, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtECInfo h_emlrtECI = { -1, 62, 9, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 61, 12, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtECInfo i_emlrtECI = { -1, 61, 5, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 63, 25, "b", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 63, 37, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtECInfo j_emlrtECI = { -1, 63, 20, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 63, 52, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 64, 14, "a", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 64, 27, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 64, 46, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtECInfo k_emlrtECI = { -1, 64, 20, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 65, 18, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtECInfo l_emlrtECI = { -1, 64, 9, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 63, 12, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtECInfo m_emlrtECI = { -1, 63, 5, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 68, 21, "b", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 68, 32, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtECInfo n_emlrtECI = { 2, 68, 19, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 68, 47, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo u_emlrtBCI = { -1, -1, 69, 11, "a", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 69, 23, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo w_emlrtBCI = { -1, -1, 69, 37, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtECInfo o_emlrtECI = { 2, 69, 19, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 69, 53, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtECInfo p_emlrtECI = { 2, 69, 9, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtBCInfo y_emlrtBCI = { -1, -1, 68, 9, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtECInfo q_emlrtECI = { -1, 68, 5, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtBCInfo ab_emlrtBCI = { -1, -1, 70, 21, "b", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo bb_emlrtBCI = { -1, -1, 70, 33, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtECInfo r_emlrtECI = { 2, 70, 19, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 70, 47, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo db_emlrtBCI = { -1, -1, 71, 11, "a", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo eb_emlrtBCI = { -1, -1, 71, 24, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo fb_emlrtBCI = { -1, -1, 71, 41, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtECInfo s_emlrtECI = { 2, 71, 20, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtBCInfo gb_emlrtBCI = { -1, -1, 71, 58, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtECInfo t_emlrtECI = { 2, 71, 9, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtBCInfo hb_emlrtBCI = { -1, -1, 70, 9, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtECInfo u_emlrtECI = { -1, 70, 5, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtBCInfo ib_emlrtBCI = { -1, -1, 74, 22, "b", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo jb_emlrtBCI = { -1, -1, 74, 26, "b", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo kb_emlrtBCI = { -1, -1, 74, 34, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo lb_emlrtBCI = { -1, -1, 74, 37, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo mb_emlrtBCI = { -1, -1, 74, 48, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo nb_emlrtBCI = { -1, -1, 74, 51, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo ob_emlrtBCI = { -1, -1, 75, 11, "a", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo pb_emlrtBCI = { -1, -1, 75, 15, "a", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo qb_emlrtBCI = { -1, -1, 75, 23, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo rb_emlrtBCI = { -1, -1, 75, 25, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo sb_emlrtBCI = { -1, -1, 75, 36, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo tb_emlrtBCI = { -1, -1, 75, 38, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo ub_emlrtBCI = { -1, -1, 74, 9, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo vb_emlrtBCI = { -1, -1, 74, 12, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo wb_emlrtBCI = { -1, -1, 76, 26, "b", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo xb_emlrtBCI = { -1, -1, 76, 37, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo yb_emlrtBCI = { -1, -1, 76, 51, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo ac_emlrtBCI = { -1, -1, 77, 15, "a", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo bc_emlrtBCI = { -1, -1, 77, 26, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo cc_emlrtBCI = { -1, -1, 77, 41, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo dc_emlrtBCI = { -1, -1, 76, 12, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo ec_emlrtBCI = { -1, -1, 78, 22, "b", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo fc_emlrtBCI = { -1, -1, 78, 34, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo gc_emlrtBCI = { -1, -1, 78, 48, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo hc_emlrtBCI = { -1, -1, 79, 11, "a", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo ic_emlrtBCI = { -1, -1, 79, 23, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo jc_emlrtBCI = { -1, -1, 79, 38, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo kc_emlrtBCI = { -1, -1, 78, 9, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtECInfo v_emlrtECI = { -1, 84, 5, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtECInfo w_emlrtECI = { -1, 85, 5, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtBCInfo lc_emlrtBCI = { -1, -1, 89, 49, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo mc_emlrtBCI = { -1, -1, 89, 17, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtECInfo x_emlrtECI = { -1, 89, 9, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtBCInfo nc_emlrtBCI = { -1, -1, 90, 49, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo oc_emlrtBCI = { -1, -1, 90, 17, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtECInfo y_emlrtECI = { -1, 90, 9, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtBCInfo pc_emlrtBCI = { -1, -1, 92, 56, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo qc_emlrtBCI = { -1, -1, 92, 17, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtECInfo ab_emlrtECI = { -1, 92, 9, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtBCInfo rc_emlrtBCI = { -1, -1, 93, 56, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo sc_emlrtBCI = { -1, -1, 93, 17, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtECInfo bb_emlrtECI = { -1, 93, 9, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtBCInfo tc_emlrtBCI = { -1, -1, 95, 50, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo uc_emlrtBCI = { -1, -1, 95, 13, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtECInfo cb_emlrtECI = { -1, 95, 9, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtBCInfo vc_emlrtBCI = { -1, -1, 96, 50, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo wc_emlrtBCI = { -1, -1, 96, 13, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtECInfo db_emlrtECI = { -1, 96, 9, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtBCInfo xc_emlrtBCI = { -1, -1, 100, 22, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo yc_emlrtBCI = { -1, -1, 41, 8, "data", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtECInfo eb_emlrtECI = { -1, 41, 1, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtBCInfo ad_emlrtBCI = { -1, -1, 100, 12, "data", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtECInfo fb_emlrtECI = { -1, 100, 5, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtBCInfo bd_emlrtBCI = { -1, -1, 108, 18, "snapshot", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtECInfo gb_emlrtECI = { -1, 108, 5, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m" };

static emlrtDCInfo emlrtDCI = { 31, 17, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 1 };

static emlrtDCInfo b_emlrtDCI = { 31, 17, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 4 };

static emlrtBCInfo cd_emlrtBCI = { -1, -1, 56, 22, "b", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtDCInfo c_emlrtDCI = { 56, 22, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 1 };

static emlrtBCInfo dd_emlrtBCI = { -1, -1, 56, 25, "b", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtDCInfo d_emlrtDCI = { 56, 25, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 1 };

static emlrtBCInfo ed_emlrtBCI = { -1, -1, 56, 34, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo fd_emlrtBCI = { -1, -1, 56, 37, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo gd_emlrtBCI = { -1, -1, 56, 49, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo hd_emlrtBCI = { -1, -1, 56, 52, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo id_emlrtBCI = { -1, -1, 57, 24, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo jd_emlrtBCI = { -1, -1, 57, 27, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo kd_emlrtBCI = { -1, -1, 57, 41, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo ld_emlrtBCI = { -1, -1, 57, 44, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo md_emlrtBCI = { -1, -1, 58, 13, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo nd_emlrtBCI = { -1, -1, 58, 18, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo od_emlrtBCI = { -1, -1, 58, 30, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo pd_emlrtBCI = { -1, -1, 58, 35, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo qd_emlrtBCI = { -1, -1, 57, 11, "a", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo rd_emlrtBCI = { -1, -1, 57, 14, "a", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo sd_emlrtBCI = { -1, -1, 56, 9, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo td_emlrtBCI = { -1, -1, 56, 12, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo ud_emlrtBCI = { -1, -1, 61, 21, "b", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo vd_emlrtBCI = { -1, -1, 61, 32, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo wd_emlrtBCI = { -1, -1, 61, 46, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo xd_emlrtBCI = { -1, -1, 62, 23, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo yd_emlrtBCI = { -1, -1, 62, 37, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo ae_emlrtBCI = { -1, -1, 62, 53, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo be_emlrtBCI = { -1, -1, 62, 11, "a", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo ce_emlrtBCI = { -1, -1, 61, 9, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo de_emlrtBCI = { -1, -1, 63, 22, "b", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo ee_emlrtBCI = { -1, -1, 63, 34, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo fe_emlrtBCI = { -1, -1, 63, 49, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo ge_emlrtBCI = { -1, -1, 64, 24, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo he_emlrtBCI = { -1, -1, 64, 41, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo ie_emlrtBCI = { -1, -1, 65, 13, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo je_emlrtBCI = { -1, -1, 64, 11, "a", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo ke_emlrtBCI = { -1, -1, 63, 9, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo le_emlrtBCI = { -1, -1, 68, 23, "b", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo me_emlrtBCI = { -1, -1, 68, 34, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo ne_emlrtBCI = { -1, -1, 68, 49, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo oe_emlrtBCI = { -1, -1, 69, 25, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo pe_emlrtBCI = { -1, -1, 69, 39, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo qe_emlrtBCI = { -1, -1, 69, 55, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo re_emlrtBCI = { -1, -1, 69, 13, "a", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo se_emlrtBCI = { -1, -1, 68, 11, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo te_emlrtBCI = { -1, -1, 70, 24, "b", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo ue_emlrtBCI = { -1, -1, 70, 36, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo ve_emlrtBCI = { -1, -1, 70, 50, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo we_emlrtBCI = { -1, -1, 71, 29, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo xe_emlrtBCI = { -1, -1, 71, 44, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo ye_emlrtBCI = { -1, -1, 71, 61, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo af_emlrtBCI = { -1, -1, 71, 14, "a", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo bf_emlrtBCI = { -1, -1, 70, 12, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo cf_emlrtBCI = { -1, -1, 76, 9, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo df_emlrtBCI = { -1, -1, 76, 22, "b", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo ef_emlrtBCI = { -1, -1, 76, 34, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo ff_emlrtBCI = { -1, -1, 76, 48, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo gf_emlrtBCI = { -1, -1, 77, 11, "a", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo hf_emlrtBCI = { -1, -1, 77, 23, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo if_emlrtBCI = { -1, -1, 77, 36, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo jf_emlrtBCI = { -1, -1, 78, 12, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo kf_emlrtBCI = { -1, -1, 78, 25, "b", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo lf_emlrtBCI = { -1, -1, 78, 37, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo mf_emlrtBCI = { -1, -1, 78, 51, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo nf_emlrtBCI = { -1, -1, 79, 14, "a", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo of_emlrtBCI = { -1, -1, 79, 25, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo pf_emlrtBCI = { -1, -1, 79, 40, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo qf_emlrtBCI = { -1, -1, 80, 9, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo rf_emlrtBCI = { -1, -1, 80, 12, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo sf_emlrtBCI = { -1, -1, 80, 22, "b", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo tf_emlrtBCI = { -1, -1, 80, 25, "b", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo uf_emlrtBCI = { -1, -1, 80, 34, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo vf_emlrtBCI = { -1, -1, 80, 37, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo wf_emlrtBCI = { -1, -1, 80, 48, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo xf_emlrtBCI = { -1, -1, 80, 51, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo yf_emlrtBCI = { -1, -1, 81, 11, "a", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo ag_emlrtBCI = { -1, -1, 81, 14, "a", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo bg_emlrtBCI = { -1, -1, 81, 23, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo cg_emlrtBCI = { -1, -1, 81, 28, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo dg_emlrtBCI = { -1, -1, 81, 39, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo eg_emlrtBCI = { -1, -1, 81, 42, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo fg_emlrtBCI = { -1, -1, 89, 13, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtDCInfo e_emlrtDCI = { 89, 13, "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 1 };

static emlrtBCInfo gg_emlrtBCI = { -1, -1, 89, 45, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo hg_emlrtBCI = { -1, -1, 90, 13, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo ig_emlrtBCI = { -1, -1, 90, 45, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo jg_emlrtBCI = { -1, -1, 92, 13, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo kg_emlrtBCI = { 1, 20, 92, 27, "boundary", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo lg_emlrtBCI = { -1, -1, 92, 52, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo mg_emlrtBCI = { -1, -1, 93, 13, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo ng_emlrtBCI = { 1, 20, 93, 27, "boundary", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo og_emlrtBCI = { -1, -1, 93, 52, "fdm", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo pg_emlrtBCI = { 1, 20, 95, 25, "boundary", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

static emlrtBCInfo qg_emlrtBCI = { 1, 20, 96, 25, "boundary", "fm2d",
  "/home/atupal/src/sc14/seismicCompetition-final/rtm/fm2d.m", 0 };

/* Function Definitions */
void fm2d(fm2dStackData *SD, const emlrtStack *sp, const real_T v_data[], const
          int32_T v_size[2], const real_T model_data[], const int32_T
          model_size[2], real_T dx, real_T nt, real_T dt, emxArray_real_T *data,
          emxArray_real_T *snapshot)
{
  real_T d0;
  int32_T i0;
  int32_T loop_ub;
  emxArray_real_T *fdm;
  real_T boundary[20];
  static const real_T dv0[20] = { 0.92198622120531026, 0.92969379475695435,
    0.93704403698365013, 0.94402748291783567, 0.95063509185869843,
    0.95685826686190967, 0.96268887336852249, 0.96811925691656275,
    0.9731422598813525, 0.97775123719333634, 0.98194007098510672,
    0.985703184122443, 0.98903555257747811, 0.99193271660557114,
    0.99439079069108094, 0.99640647223099332, 0.99797704892923944,
    0.99910040487852736, 0.99977502531060169, 1.0 };

  int32_T tmp_data[120];
  int32_T b_tmp_data[50];
  int32_T iv0[2];
  int32_T absb;
  int32_T i1;
  int32_T iv1[1];
  int32_T b_model_size[2];
  int32_T model[2];
  real_T b_model_data[50];
  int32_T b_v_size[2];
  int32_T a_size[2];
  int32_T n;
  int32_T apnd;
  int32_T ndbl;
  int32_T cdiff;
  real_T iz_data[118];
  int32_T b_n;
  real_T y_data[118];
  int32_T c_n;
  real_T izb_data[100];
  int32_T it;
  int32_T i2;
  int32_T b_size[2];
  int32_T fdm_size[2];
  int32_T tmp_size[2];
  int32_T b_fdm_size[2];
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T c_fdm_size[2];
  int32_T d_fdm_size[2];
  real_T c_tmp_data[5664];
  int32_T e_fdm_size[2];
  int32_T f_fdm_size[2];
  real_T d_tmp_data[5664];
  int32_T g_fdm_size[2];
  int32_T h_fdm_size[2];
  int32_T b_a_size[2];
  int32_T i_fdm_size[2];
  int32_T b_tmp_size[2];
  real_T e_tmp_data[5664];
  int32_T f_tmp_data[118];
  int32_T g_tmp_data[48];
  int32_T iv2[2];
  real_T h_tmp_data[5664];
  int32_T c_tmp_size[1];
  real_T i_tmp_data[118];
  real_T j_tmp_data[118];
  real_T k_tmp_data[118];
  real_T l_tmp_data[118];
  int32_T iv3[1];
  real_T m_tmp_data[118];
  int32_T iv4[1];
  int32_T b_b_size[2];
  int32_T j_fdm_size[2];
  int32_T d_tmp_size[2];
  real_T n_tmp_data[48];
  int32_T k_fdm_size[2];
  real_T o_tmp_data[48];
  int32_T l_fdm_size[2];
  int32_T m_fdm_size[2];
  real_T p_tmp_data[48];
  int32_T n_fdm_size[2];
  int32_T o_fdm_size[2];
  int32_T c_a_size[2];
  int32_T p_fdm_size[2];
  int32_T e_tmp_size[2];
  real_T q_tmp_data[48];
  int32_T iv5[2];
  real_T r_tmp_data[48];
  int32_T c_b_size[2];
  int32_T q_fdm_size[2];
  int32_T r_fdm_size[2];
  int32_T s_fdm_size[2];
  int32_T t_fdm_size[2];
  int32_T u_fdm_size[2];
  int32_T v_fdm_size[2];
  int32_T d_a_size[2];
  int32_T w_fdm_size[2];
  int32_T iv6[2];
  int32_T i6;
  int32_T iv7[2];
  int32_T x_fdm_size[2];
  int32_T iv8[2];
  int32_T y_fdm_size[2];
  int32_T s_tmp_data[100];
  real_T t_tmp_data[100];
  int32_T f_tmp_size[1];
  int32_T iv9[1];
  int32_T iv10[1];
  int32_T iv11[1];
  int32_T iv12[1];
  int32_T g_tmp_size[2];
  int32_T iv13[2];
  int32_T iv14[2];
  int32_T iv15[1];
  int32_T ab_fdm_size[2];
  int32_T iv16[2];
  int32_T bb_fdm_size[2];
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  */
  /*  model(nz,nx)      model vector */
  /*  v(nz,nx)          velocity model */
  /*  nx                number of horizontal samples */
  /*  nz                number of depth samples */
  /*  nt                numer of time samples */
  /*  dx                horizontal distance per sample */
  /*  dz                depth distance per sample */
  /*  dt                time difference per sample */
  /*  add grid points for boundary condition */
  /* model = [repmat(model(:,1),1,20), model, repmat(model(:,end),1,20)]; */
  /* model(end+20,:) = model(end,:); */
  /* v = [repmat(v(:,1),1,20), v, repmat(v(:,end),1,20)]; */
  /* v(end+20,:) = v(end,:); */
  /* % Initialize storage */
  d0 = emlrtNonNegativeCheckFastR2012b(nt, &b_emlrtDCI, sp);
  emlrtIntegerCheckFastR2012b(d0, &emlrtDCI, sp);
  i0 = data->size[0] * data->size[1];
  data->size[0] = model_size[1];
  emxEnsureCapacity(sp, (emxArray__common *)data, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  d0 = emlrtNonNegativeCheckFastR2012b(nt, &b_emlrtDCI, sp);
  emlrtIntegerCheckFastR2012b(d0, &emlrtDCI, sp);
  i0 = data->size[0] * data->size[1];
  data->size[1] = (int32_T)nt;
  emxEnsureCapacity(sp, (emxArray__common *)data, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  d0 = emlrtNonNegativeCheckFastR2012b(nt, &b_emlrtDCI, sp);
  loop_ub = model_size[1] * (int32_T)emlrtIntegerCheckFastR2012b(d0, &emlrtDCI,
    sp);
  for (i0 = 0; i0 < loop_ub; i0++) {
    data->data[i0] = 0.0;
  }

  emxInit_real_T(sp, &fdm, 3, &b_emlrtRTEI, true);
  i0 = fdm->size[0] * fdm->size[1] * fdm->size[2];
  fdm->size[0] = model_size[0];
  emxEnsureCapacity(sp, (emxArray__common *)fdm, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  i0 = fdm->size[0] * fdm->size[1] * fdm->size[2];
  fdm->size[1] = model_size[1];
  fdm->size[2] = 3;
  emxEnsureCapacity(sp, (emxArray__common *)fdm, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = model_size[0] * model_size[1] * 3;
  for (i0 = 0; i0 < loop_ub; i0++) {
    fdm->data[i0] = 0.0;
  }

  /* % Boundary Absorbing Model */
  power(dv0, boundary);

  /* % Forward-Time Modeling */
  loop_ub = model_size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    tmp_data[i0] = i0;
  }

  loop_ub = model_size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_tmp_data[i0] = i0;
  }

  iv0[0] = model_size[0];
  iv0[1] = model_size[1];
  emlrtSubAssignSizeCheckR2012b(iv0, 2, model_size, 2, &emlrtECI, sp);
  loop_ub = model_size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    absb = model_size[0];
    for (i1 = 0; i1 < absb; i1++) {
      fdm->data[(tmp_data[i1] + fdm->size[0] * b_tmp_data[i0]) + fdm->size[0] *
        fdm->size[1]] = model_data[i1 + model_size[0] * i0];
    }
  }

  loop_ub = model_size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_tmp_data[i0] = i0;
  }

  i0 = (int32_T)nt;
  emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &yc_emlrtBCI, sp);
  emlrtDynamicBoundsCheckFastR2012b(1, 1, model_size[0], &emlrtBCI, sp);
  iv1[0] = model_size[1];
  b_model_size[0] = 1;
  b_model_size[1] = model_size[1];
  for (i0 = 0; i0 < 2; i0++) {
    model[i0] = b_model_size[i0];
  }

  emlrtSubAssignSizeCheckR2012b(iv1, 1, model, 2, &eb_emlrtECI, sp);
  loop_ub = model_size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_model_data[i0] = model_data[model_size[0] * i0];
  }

  loop_ub = model_size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    data->data[b_tmp_data[i0]] = b_model_data[i0];
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
  if (model_size[0] - 1 < 2) {
    n = -1;
    apnd = model_size[0] - 1;
  } else {
    ndbl = (int32_T)muDoubleScalarFloor((((real_T)model_size[0] - 1.0) - 2.0) +
      0.5);
    apnd = ndbl + 2;
    cdiff = (ndbl - model_size[0]) + 3;
    absb = (int32_T)muDoubleScalarAbs((real_T)model_size[0] - 1.0);
    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)
        muIntScalarMax_sint32(2, absb)) {
      ndbl++;
      apnd = model_size[0] - 1;
    } else if (cdiff > 0) {
      apnd = ndbl + 1;
    } else {
      ndbl++;
    }

    n = ndbl - 1;
  }

  if (n + 1 > 0) {
    iz_data[0] = 2.0;
    if (n + 1 > 1) {
      iz_data[n] = apnd;
      i0 = n + (n < 0);
      if (i0 >= 0) {
        ndbl = (int32_T)((uint32_T)i0 >> 1);
      } else {
        ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
      }

      for (cdiff = 1; cdiff < ndbl; cdiff++) {
        iz_data[cdiff] = 2.0 + (real_T)cdiff;
        iz_data[n - cdiff] = apnd - cdiff;
      }

      if (ndbl << 1 == n) {
        iz_data[ndbl] = (2.0 + (real_T)apnd) / 2.0;
      } else {
        iz_data[ndbl] = 2.0 + (real_T)ndbl;
        iz_data[ndbl + 1] = apnd - ndbl;
      }
    }
  }

  /*  interior z */
  if (model_size[1] - 1 < 2) {
    b_n = -1;
    apnd = model_size[1] - 1;
  } else {
    ndbl = (int32_T)muDoubleScalarFloor((((real_T)model_size[1] - 1.0) - 2.0) +
      0.5);
    apnd = ndbl + 2;
    cdiff = (ndbl - model_size[1]) + 3;
    absb = (int32_T)muDoubleScalarAbs((real_T)model_size[1] - 1.0);
    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)
        muIntScalarMax_sint32(2, absb)) {
      ndbl++;
      apnd = model_size[1] - 1;
    } else if (cdiff > 0) {
      apnd = ndbl + 1;
    } else {
      ndbl++;
    }

    b_n = ndbl - 1;
  }

  if (b_n + 1 > 0) {
    y_data[0] = 2.0;
    if (b_n + 1 > 1) {
      y_data[b_n] = apnd;
      i0 = b_n + (b_n < 0);
      if (i0 >= 0) {
        ndbl = (int32_T)((uint32_T)i0 >> 1);
      } else {
        ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
      }

      for (cdiff = 1; cdiff < ndbl; cdiff++) {
        y_data[cdiff] = 2.0 + (real_T)cdiff;
        y_data[b_n - cdiff] = apnd - cdiff;
      }

      if (ndbl << 1 == b_n) {
        y_data[ndbl] = (2.0 + (real_T)apnd) / 2.0;
      } else {
        y_data[ndbl] = 2.0 + (real_T)ndbl;
        y_data[ndbl + 1] = apnd - ndbl;
      }
    }
  }

  /*  interior x */
  if (model_size[0] - 20 < 1) {
    c_n = -1;
    apnd = model_size[0] - 20;
  } else {
    ndbl = (int32_T)muDoubleScalarFloor((((real_T)model_size[0] - 20.0) - 1.0) +
      0.5);
    apnd = ndbl + 1;
    cdiff = (ndbl - model_size[0]) + 21;
    absb = (int32_T)muDoubleScalarAbs((real_T)model_size[0] - 20.0);
    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)
        muIntScalarMax_sint32(1, absb)) {
      ndbl++;
      apnd = model_size[0] - 20;
    } else if (cdiff > 0) {
      apnd = ndbl;
    } else {
      ndbl++;
    }

    c_n = ndbl - 1;
  }

  if (c_n + 1 > 0) {
    izb_data[0] = 1.0;
    if (c_n + 1 > 1) {
      izb_data[c_n] = apnd;
      i0 = c_n + (c_n < 0);
      if (i0 >= 0) {
        ndbl = (int32_T)((uint32_T)i0 >> 1);
      } else {
        ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
      }

      for (cdiff = 1; cdiff < ndbl; cdiff++) {
        izb_data[cdiff] = 1.0 + (real_T)cdiff;
        izb_data[c_n - cdiff] = apnd - cdiff;
      }

      if (ndbl << 1 == c_n) {
        izb_data[ndbl] = (1.0 + (real_T)apnd) / 2.0;
      } else {
        izb_data[ndbl] = 1.0 + (real_T)ndbl;
        izb_data[ndbl + 1] = apnd - ndbl;
      }
    }
  }

  /*  boundary z */
  i0 = snapshot->size[0] * snapshot->size[1] * snapshot->size[2];
  snapshot->size[0] = model_size[0];
  emxEnsureCapacity(sp, (emxArray__common *)snapshot, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  i0 = snapshot->size[0] * snapshot->size[1] * snapshot->size[2];
  snapshot->size[1] = model_size[1];
  emxEnsureCapacity(sp, (emxArray__common *)snapshot, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  i0 = snapshot->size[0] * snapshot->size[1] * snapshot->size[2];
  snapshot->size[2] = (int32_T)nt;
  emxEnsureCapacity(sp, (emxArray__common *)snapshot, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = model_size[0] * model_size[1] * (int32_T)nt;
  for (i0 = 0; i0 < loop_ub; i0++) {
    snapshot->data[i0] = 1.0;
  }

  emlrtForLoopVectorCheckR2012b(2.0, 1.0, nt, mxDOUBLE_CLASS, (int32_T)(nt +
    -1.0), &d_emlrtRTEI, sp);
  it = 0;
  while (it <= (int32_T)(nt + -1.0) - 1) {
    /*  finite differencing on interior */
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = (int32_T)emlrtIntegerCheckFastR2012b(iz_data[i0], &c_emlrtDCI, sp);
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, a_size[0], &cd_emlrtBCI, sp);
    }

    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = (int32_T)emlrtIntegerCheckFastR2012b(y_data[i0], &d_emlrtDCI, sp);
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, a_size[1], &dd_emlrtBCI, sp);
    }

    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)iz_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &ed_emlrtBCI, sp);
    }

    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[1];
      i2 = (int32_T)y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &fd_emlrtBCI, sp);
    }

    b_size[0] = n + 1;
    b_size[1] = b_n + 1;
    fdm_size[0] = n + 1;
    fdm_size[1] = b_n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      model[i0] = b_size[i0];
      b_model_size[i0] = fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(model, b_model_size, &b_emlrtECI, sp);
    tmp_size[0] = n + 1;
    tmp_size[1] = b_n + 1;
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      absb = n + 1;
      for (i1 = 0; i1 < absb; i1++) {
        SD->f0.tmp_data[i1 + (n + 1) * i0] = SD->f0.b_data[((int32_T)iz_data[i1]
          + a_size[0] * ((int32_T)y_data[i0] - 1)) - 1] * fdm->data[(((int32_T)
          iz_data[i1] + fdm->size[0] * ((int32_T)y_data[i0] - 1)) + fdm->size[0]
          * fdm->size[1]) - 1];
      }
    }

    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)iz_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &gd_emlrtBCI, sp);
    }

    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[1];
      i2 = (int32_T)y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &hd_emlrtBCI, sp);
    }

    b_fdm_size[0] = n + 1;
    b_fdm_size[1] = b_n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      iv0[i0] = tmp_size[i0];
      b_model_size[i0] = b_fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(iv0, b_model_size, &b_emlrtECI, sp);
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      absb = n + 1;
      for (i1 = 0; i1 < absb; i1++) {
        i2 = fdm->size[0];
        i3 = (int32_T)iz_data[i1];
        i4 = fdm->size[1];
        i5 = (int32_T)(y_data[i0] + 1.0);
        SD->f0.b_tmp_data[i1 + (n + 1) * i0] = fdm->data
          [((emlrtDynamicBoundsCheckFastR2012b(i3, 1, i2, &id_emlrtBCI, sp) +
             fdm->size[0] * (emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4,
               &jd_emlrtBCI, sp) - 1)) + fdm->size[0] * fdm->size[1]) - 1];
      }
    }

    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      absb = n + 1;
      for (i1 = 0; i1 < absb; i1++) {
        i2 = fdm->size[0];
        i3 = (int32_T)iz_data[i1];
        i4 = fdm->size[1];
        i5 = (int32_T)(y_data[i0] - 1.0);
        SD->f0.c_tmp_data[i1 + (n + 1) * i0] = fdm->data
          [((emlrtDynamicBoundsCheckFastR2012b(i3, 1, i2, &kd_emlrtBCI, sp) +
             fdm->size[0] * (emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4,
               &ld_emlrtBCI, sp) - 1)) + fdm->size[0] * fdm->size[1]) - 1];
      }
    }

    c_fdm_size[0] = n + 1;
    c_fdm_size[1] = b_n + 1;
    d_fdm_size[0] = n + 1;
    d_fdm_size[1] = b_n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      b_model_size[i0] = c_fdm_size[i0];
      model[i0] = d_fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(b_model_size, model, &c_emlrtECI, sp);
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      absb = n + 1;
      for (i1 = 0; i1 < absb; i1++) {
        i2 = fdm->size[0];
        i3 = (int32_T)(iz_data[i1] + 1.0);
        i4 = fdm->size[1];
        i5 = (int32_T)y_data[i0];
        c_tmp_data[i1 + (n + 1) * i0] = fdm->data
          [((emlrtDynamicBoundsCheckFastR2012b(i3, 1, i2, &md_emlrtBCI, sp) +
             fdm->size[0] * (emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4,
               &nd_emlrtBCI, sp) - 1)) + fdm->size[0] * fdm->size[1]) - 1];
      }
    }

    e_fdm_size[0] = n + 1;
    e_fdm_size[1] = b_n + 1;
    f_fdm_size[0] = n + 1;
    f_fdm_size[1] = b_n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      b_model_size[i0] = e_fdm_size[i0];
      model[i0] = f_fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(b_model_size, model, &c_emlrtECI, sp);
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      absb = n + 1;
      for (i1 = 0; i1 < absb; i1++) {
        i2 = fdm->size[0];
        i3 = (int32_T)(iz_data[i1] - 1.0);
        i4 = fdm->size[1];
        i5 = (int32_T)y_data[i0];
        d_tmp_data[i1 + (n + 1) * i0] = fdm->data
          [((emlrtDynamicBoundsCheckFastR2012b(i3, 1, i2, &od_emlrtBCI, sp) +
             fdm->size[0] * (emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4,
               &pd_emlrtBCI, sp) - 1)) + fdm->size[0] * fdm->size[1]) - 1];
      }
    }

    g_fdm_size[0] = n + 1;
    g_fdm_size[1] = b_n + 1;
    h_fdm_size[0] = n + 1;
    h_fdm_size[1] = b_n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      b_model_size[i0] = g_fdm_size[i0];
      model[i0] = h_fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(b_model_size, model, &c_emlrtECI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = (int32_T)iz_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, a_size[0], &qd_emlrtBCI, sp);
    }

    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = (int32_T)y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, a_size[1], &rd_emlrtBCI, sp);
    }

    b_a_size[0] = n + 1;
    b_a_size[1] = b_n + 1;
    i_fdm_size[0] = n + 1;
    i_fdm_size[1] = b_n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      model[i0] = b_a_size[i0];
      b_model_size[i0] = i_fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(model, b_model_size, &d_emlrtECI, sp);
    b_tmp_size[0] = n + 1;
    b_tmp_size[1] = b_n + 1;
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      absb = n + 1;
      for (i1 = 0; i1 < absb; i1++) {
        e_tmp_data[i1 + (n + 1) * i0] = SD->f0.a_data[((int32_T)iz_data[i1] +
          a_size[0] * ((int32_T)y_data[i0] - 1)) - 1] * (((SD->f0.b_tmp_data[i1
          + (n + 1) * i0] + SD->f0.c_tmp_data[i1 + (n + 1) * i0]) +
          c_tmp_data[i1 + (n + 1) * i0]) + d_tmp_data[i1 + (n + 1) * i0]);
      }
    }

    for (i0 = 0; i0 < 2; i0++) {
      iv0[i0] = tmp_size[i0];
      model[i0] = b_tmp_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(iv0, model, &b_emlrtECI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)iz_data[i0];
      f_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &sd_emlrtBCI,
        sp) - 1;
    }

    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[1];
      i2 = (int32_T)y_data[i0];
      g_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &td_emlrtBCI,
        sp) - 1;
    }

    iv2[0] = n + 1;
    iv2[1] = b_n + 1;
    emlrtSubAssignSizeCheckR2012b(iv2, 2, tmp_size, 2, &e_emlrtECI, sp);
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      absb = n + 1;
      for (i1 = 0; i1 < absb; i1++) {
        h_tmp_data[i1 + (n + 1) * i0] = (SD->f0.tmp_data[i1 + (n + 1) * i0] -
          fdm->data[((int32_T)iz_data[i1] + fdm->size[0] * ((int32_T)y_data[i0]
          - 1)) - 1]) + e_tmp_data[i1 + (n + 1) * i0];
      }
    }

    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      absb = n + 1;
      for (i1 = 0; i1 < absb; i1++) {
        fdm->data[(f_tmp_data[i1] + fdm->size[0] * g_tmp_data[i0]) + (fdm->size
          [0] * fdm->size[1] << 1)] = h_tmp_data[i1 + (n + 1) * i0];
      }
    }

    /*  finite differencing at ix = 1 and ix = nx (surface, bottom) */
    emlrtDynamicBoundsCheckFastR2012b(1, 1, a_size[1], &b_emlrtBCI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = (int32_T)iz_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, a_size[0], &ud_emlrtBCI, sp);
    }

    i0 = fdm->size[1];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &c_emlrtBCI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)iz_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &vd_emlrtBCI, sp);
    }

    emlrtSizeEqCheck1DFastR2012b(n + 1, n + 1, &f_emlrtECI, sp);
    c_tmp_size[0] = n + 1;
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i_tmp_data[i0] = SD->f0.b_data[(int32_T)iz_data[i0] - 1] * fdm->data
        [((int32_T)iz_data[i0] + fdm->size[0] * fdm->size[1]) - 1];
    }

    i0 = fdm->size[1];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &d_emlrtBCI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)iz_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &wd_emlrtBCI, sp);
    }

    emlrtSizeEqCheck1DFastR2012b(n + 1, n + 1, &f_emlrtECI, sp);
    i0 = fdm->size[1];
    emlrtDynamicBoundsCheckFastR2012b(2, 1, i0, &f_emlrtBCI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)iz_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &xd_emlrtBCI, sp);
    }

    i0 = fdm->size[1];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &g_emlrtBCI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)(iz_data[i0] + 1.0);
      j_tmp_data[i0] = fdm->data[(emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
        &yd_emlrtBCI, sp) + fdm->size[0] * fdm->size[1]) - 1];
    }

    emlrtSizeEqCheck1DFastR2012b(n + 1, n + 1, &g_emlrtECI, sp);
    i0 = fdm->size[1];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &h_emlrtBCI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)(iz_data[i0] - 1.0);
      k_tmp_data[i0] = fdm->data[(emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
        &ae_emlrtBCI, sp) + fdm->size[0] * fdm->size[1]) - 1];
    }

    emlrtSizeEqCheck1DFastR2012b(n + 1, n + 1, &g_emlrtECI, sp);
    emlrtDynamicBoundsCheckFastR2012b(1, 1, a_size[1], &e_emlrtBCI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = (int32_T)iz_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, a_size[0], &be_emlrtBCI, sp);
    }

    emlrtSizeEqCheck1DFastR2012b(n + 1, n + 1, &h_emlrtECI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      l_tmp_data[i0] = SD->f0.a_data[(int32_T)iz_data[i0] - 1] * ((fdm->data
        [(((int32_T)iz_data[i0] + fdm->size[0]) + fdm->size[0] * fdm->size[1]) -
        1] + j_tmp_data[i0]) + k_tmp_data[i0]);
    }

    emlrtSizeEqCheck1DFastR2012b(n + 1, n + 1, &f_emlrtECI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)iz_data[i0];
      f_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &ce_emlrtBCI,
        sp) - 1;
    }

    i0 = fdm->size[1];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &i_emlrtBCI, sp);
    iv3[0] = n + 1;
    emlrtSubAssignSizeCheckR2012b(iv3, 1, c_tmp_size, 1, &i_emlrtECI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      m_tmp_data[i0] = (i_tmp_data[i0] - fdm->data[(int32_T)iz_data[i0] - 1]) +
        l_tmp_data[i0];
    }

    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      fdm->data[f_tmp_data[i0] + (fdm->size[0] * fdm->size[1] << 1)] =
        m_tmp_data[i0];
    }

    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = (int32_T)iz_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, a_size[0], &de_emlrtBCI, sp);
    }

    i0 = model_size[1];
    emlrtDynamicBoundsCheckFastR2012b(i0, 1, a_size[1], &j_emlrtBCI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)iz_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &ee_emlrtBCI, sp);
    }

    i0 = fdm->size[1];
    i1 = model_size[1];
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &k_emlrtBCI, sp);
    emlrtSizeEqCheck1DFastR2012b(n + 1, n + 1, &j_emlrtECI, sp);
    c_tmp_size[0] = n + 1;
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i_tmp_data[i0] = SD->f0.b_data[((int32_T)iz_data[i0] + a_size[0] *
        (model_size[1] - 1)) - 1] * fdm->data[(((int32_T)iz_data[i0] + fdm->
        size[0] * (model_size[1] - 1)) + fdm->size[0] * fdm->size[1]) - 1];
    }

    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)iz_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &fe_emlrtBCI, sp);
    }

    i0 = fdm->size[1];
    i1 = model_size[1];
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &l_emlrtBCI, sp);
    emlrtSizeEqCheck1DFastR2012b(n + 1, n + 1, &j_emlrtECI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)iz_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &ge_emlrtBCI, sp);
    }

    i0 = fdm->size[1];
    i1 = (int32_T)((real_T)model_size[1] - 1.0);
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &n_emlrtBCI, sp);
    i0 = fdm->size[1];
    ndbl = emlrtDynamicBoundsCheckFastR2012b(model_size[1], 1, i0, &o_emlrtBCI,
      sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)(iz_data[i0] + 1.0);
      j_tmp_data[i0] = fdm->data[((emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
        &he_emlrtBCI, sp) + fdm->size[0] * (ndbl - 1)) + fdm->size[0] *
        fdm->size[1]) - 1];
    }

    emlrtSizeEqCheck1DFastR2012b(n + 1, n + 1, &k_emlrtECI, sp);
    i0 = fdm->size[1];
    ndbl = emlrtDynamicBoundsCheckFastR2012b(model_size[1], 1, i0, &p_emlrtBCI,
      sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)(iz_data[i0] - 1.0);
      k_tmp_data[i0] = fdm->data[((emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
        &ie_emlrtBCI, sp) + fdm->size[0] * (ndbl - 1)) + fdm->size[0] *
        fdm->size[1]) - 1];
    }

    emlrtSizeEqCheck1DFastR2012b(n + 1, n + 1, &k_emlrtECI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = (int32_T)iz_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, a_size[0], &je_emlrtBCI, sp);
    }

    i0 = model_size[1];
    emlrtDynamicBoundsCheckFastR2012b(i0, 1, a_size[1], &m_emlrtBCI, sp);
    emlrtSizeEqCheck1DFastR2012b(n + 1, n + 1, &l_emlrtECI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      l_tmp_data[i0] = SD->f0.a_data[((int32_T)iz_data[i0] + a_size[0] *
        (model_size[1] - 1)) - 1] * ((fdm->data[(((int32_T)iz_data[i0] +
        fdm->size[0] * (model_size[1] - 2)) + fdm->size[0] * fdm->size[1]) - 1]
        + j_tmp_data[i0]) + k_tmp_data[i0]);
    }

    emlrtSizeEqCheck1DFastR2012b(n + 1, n + 1, &j_emlrtECI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[0];
      i2 = (int32_T)iz_data[i0];
      f_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &ke_emlrtBCI,
        sp) - 1;
    }

    i0 = fdm->size[1];
    i1 = model_size[1];
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &q_emlrtBCI, sp);
    iv4[0] = n + 1;
    emlrtSubAssignSizeCheckR2012b(iv4, 1, c_tmp_size, 1, &m_emlrtECI, sp);
    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      m_tmp_data[i0] = (i_tmp_data[i0] - fdm->data[((int32_T)iz_data[i0] +
        fdm->size[0] * (model_size[1] - 1)) - 1]) + l_tmp_data[i0];
    }

    loop_ub = n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      fdm->data[(f_tmp_data[i0] + fdm->size[0] * (model_size[1] - 1)) +
        (fdm->size[0] * fdm->size[1] << 1)] = m_tmp_data[i0];
    }

    /*  finite differencing at iz = 1 and iz = nz (z boundaries) */
    emlrtDynamicBoundsCheckFastR2012b(1, 1, a_size[0], &r_emlrtBCI, sp);
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = (int32_T)y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, a_size[1], &le_emlrtBCI, sp);
    }

    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &s_emlrtBCI, sp);
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[1];
      i2 = (int32_T)y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &me_emlrtBCI, sp);
    }

    b_b_size[0] = 1;
    b_b_size[1] = b_n + 1;
    j_fdm_size[0] = 1;
    j_fdm_size[1] = b_n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      model[i0] = b_b_size[i0];
      b_model_size[i0] = j_fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(model, b_model_size, &n_emlrtECI, sp);
    d_tmp_size[0] = 1;
    d_tmp_size[1] = b_n + 1;
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      n_tmp_data[i0] = SD->f0.b_data[a_size[0] * ((int32_T)y_data[i0] - 1)] *
        fdm->data[fdm->size[0] * ((int32_T)y_data[i0] - 1) + fdm->size[0] *
        fdm->size[1]];
    }

    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &t_emlrtBCI, sp);
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[1];
      i2 = (int32_T)y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &ne_emlrtBCI, sp);
    }

    k_fdm_size[0] = 1;
    k_fdm_size[1] = b_n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      iv0[i0] = d_tmp_size[i0];
      b_model_size[i0] = k_fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(iv0, b_model_size, &n_emlrtECI, sp);
    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(2, 1, i0, &v_emlrtBCI, sp);
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[1];
      i2 = (int32_T)y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &oe_emlrtBCI, sp);
    }

    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &w_emlrtBCI, sp);
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[1];
      i2 = (int32_T)(y_data[i0] + 1.0);
      o_tmp_data[i0] = fdm->data[fdm->size[0] *
        (emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &pe_emlrtBCI, sp) - 1) +
        fdm->size[0] * fdm->size[1]];
    }

    l_fdm_size[0] = 1;
    l_fdm_size[1] = b_n + 1;
    m_fdm_size[0] = 1;
    m_fdm_size[1] = b_n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      b_model_size[i0] = l_fdm_size[i0];
      model[i0] = m_fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(b_model_size, model, &o_emlrtECI, sp);
    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &x_emlrtBCI, sp);
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[1];
      i2 = (int32_T)(y_data[i0] - 1.0);
      p_tmp_data[i0] = fdm->data[fdm->size[0] *
        (emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &qe_emlrtBCI, sp) - 1) +
        fdm->size[0] * fdm->size[1]];
    }

    n_fdm_size[0] = 1;
    n_fdm_size[1] = b_n + 1;
    o_fdm_size[0] = 1;
    o_fdm_size[1] = b_n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      b_model_size[i0] = n_fdm_size[i0];
      model[i0] = o_fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(b_model_size, model, &o_emlrtECI, sp);
    emlrtDynamicBoundsCheckFastR2012b(1, 1, a_size[0], &u_emlrtBCI, sp);
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = (int32_T)y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, a_size[1], &re_emlrtBCI, sp);
    }

    c_a_size[0] = 1;
    c_a_size[1] = b_n + 1;
    p_fdm_size[0] = 1;
    p_fdm_size[1] = b_n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      model[i0] = c_a_size[i0];
      b_model_size[i0] = p_fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(model, b_model_size, &p_emlrtECI, sp);
    e_tmp_size[0] = 1;
    e_tmp_size[1] = b_n + 1;
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      q_tmp_data[i0] = SD->f0.a_data[a_size[0] * ((int32_T)y_data[i0] - 1)] *
        ((fdm->data[(fdm->size[0] * ((int32_T)y_data[i0] - 1) + fdm->size[0] *
                     fdm->size[1]) + 1] + o_tmp_data[i0]) + p_tmp_data[i0]);
    }

    for (i0 = 0; i0 < 2; i0++) {
      iv0[i0] = d_tmp_size[i0];
      model[i0] = e_tmp_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(iv0, model, &n_emlrtECI, sp);
    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &y_emlrtBCI, sp);
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[1];
      i2 = (int32_T)y_data[i0];
      g_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &se_emlrtBCI,
        sp) - 1;
    }

    iv5[0] = 1;
    iv5[1] = b_n + 1;
    emlrtSubAssignSizeCheckR2012b(iv5, 2, d_tmp_size, 2, &q_emlrtECI, sp);
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      r_tmp_data[i0] = (n_tmp_data[i0] - fdm->data[fdm->size[0] * ((int32_T)
        y_data[i0] - 1)]) + q_tmp_data[i0];
    }

    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      fdm->data[fdm->size[0] * g_tmp_data[i0] + (fdm->size[0] * fdm->size[1] <<
        1)] = r_tmp_data[i0];
    }

    i0 = model_size[0];
    emlrtDynamicBoundsCheckFastR2012b(i0, 1, a_size[0], &ab_emlrtBCI, sp);
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = (int32_T)y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, a_size[1], &te_emlrtBCI, sp);
    }

    i0 = fdm->size[0];
    i1 = model_size[0];
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &bb_emlrtBCI, sp);
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[1];
      i2 = (int32_T)y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &ue_emlrtBCI, sp);
    }

    c_b_size[0] = 1;
    c_b_size[1] = b_n + 1;
    q_fdm_size[0] = 1;
    q_fdm_size[1] = b_n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      model[i0] = c_b_size[i0];
      b_model_size[i0] = q_fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(model, b_model_size, &r_emlrtECI, sp);
    d_tmp_size[0] = 1;
    d_tmp_size[1] = b_n + 1;
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      n_tmp_data[i0] = SD->f0.b_data[(model_size[0] + a_size[0] * ((int32_T)
        y_data[i0] - 1)) - 1] * fdm->data[((model_size[0] + fdm->size[0] *
        ((int32_T)y_data[i0] - 1)) + fdm->size[0] * fdm->size[1]) - 1];
    }

    i0 = fdm->size[0];
    i1 = model_size[0];
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &cb_emlrtBCI, sp);
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[1];
      i2 = (int32_T)y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &ve_emlrtBCI, sp);
    }

    r_fdm_size[0] = 1;
    r_fdm_size[1] = b_n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      iv0[i0] = d_tmp_size[i0];
      b_model_size[i0] = r_fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(iv0, b_model_size, &r_emlrtECI, sp);
    i0 = fdm->size[0];
    i1 = (int32_T)((real_T)model_size[0] - 1.0);
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &eb_emlrtBCI, sp);
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[1];
      i2 = (int32_T)y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &we_emlrtBCI, sp);
    }

    i0 = fdm->size[0];
    ndbl = emlrtDynamicBoundsCheckFastR2012b(model_size[0], 1, i0, &fb_emlrtBCI,
      sp);
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[1];
      i2 = (int32_T)(y_data[i0] + 1.0);
      o_tmp_data[i0] = fdm->data[((ndbl + fdm->size[0] *
        (emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &xe_emlrtBCI, sp) - 1)) +
        fdm->size[0] * fdm->size[1]) - 1];
    }

    s_fdm_size[0] = 1;
    s_fdm_size[1] = b_n + 1;
    t_fdm_size[0] = 1;
    t_fdm_size[1] = b_n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      b_model_size[i0] = s_fdm_size[i0];
      model[i0] = t_fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(b_model_size, model, &s_emlrtECI, sp);
    i0 = fdm->size[0];
    ndbl = emlrtDynamicBoundsCheckFastR2012b(model_size[0], 1, i0, &gb_emlrtBCI,
      sp);
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[1];
      i2 = (int32_T)(y_data[i0] - 1.0);
      p_tmp_data[i0] = fdm->data[((ndbl + fdm->size[0] *
        (emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &ye_emlrtBCI, sp) - 1)) +
        fdm->size[0] * fdm->size[1]) - 1];
    }

    u_fdm_size[0] = 1;
    u_fdm_size[1] = b_n + 1;
    v_fdm_size[0] = 1;
    v_fdm_size[1] = b_n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      b_model_size[i0] = u_fdm_size[i0];
      model[i0] = v_fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(b_model_size, model, &s_emlrtECI, sp);
    i0 = model_size[0];
    emlrtDynamicBoundsCheckFastR2012b(i0, 1, a_size[0], &db_emlrtBCI, sp);
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = (int32_T)y_data[i0];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, a_size[1], &af_emlrtBCI, sp);
    }

    d_a_size[0] = 1;
    d_a_size[1] = b_n + 1;
    w_fdm_size[0] = 1;
    w_fdm_size[1] = b_n + 1;
    for (i0 = 0; i0 < 2; i0++) {
      model[i0] = d_a_size[i0];
      b_model_size[i0] = w_fdm_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(model, b_model_size, &t_emlrtECI, sp);
    e_tmp_size[0] = 1;
    e_tmp_size[1] = b_n + 1;
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      q_tmp_data[i0] = SD->f0.a_data[(model_size[0] + a_size[0] * ((int32_T)
        y_data[i0] - 1)) - 1] * ((fdm->data[((model_size[0] + fdm->size[0] *
        ((int32_T)y_data[i0] - 1)) + fdm->size[0] * fdm->size[1]) - 2] +
        o_tmp_data[i0]) + p_tmp_data[i0]);
    }

    for (i0 = 0; i0 < 2; i0++) {
      iv0[i0] = d_tmp_size[i0];
      model[i0] = e_tmp_size[i0];
    }

    emlrtSizeEqCheck2DFastR2012b(iv0, model, &r_emlrtECI, sp);
    i0 = fdm->size[0];
    i1 = model_size[0];
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &hb_emlrtBCI, sp);
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = fdm->size[1];
      i2 = (int32_T)y_data[i0];
      g_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &bf_emlrtBCI,
        sp) - 1;
    }

    iv6[0] = 1;
    iv6[1] = b_n + 1;
    emlrtSubAssignSizeCheckR2012b(iv6, 2, d_tmp_size, 2, &u_emlrtECI, sp);
    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      r_tmp_data[i0] = (n_tmp_data[i0] - fdm->data[(model_size[0] + fdm->size[0]
        * ((int32_T)y_data[i0] - 1)) - 1]) + q_tmp_data[i0];
    }

    loop_ub = b_n + 1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      fdm->data[((model_size[0] + fdm->size[0] * g_tmp_data[i0]) + (fdm->size[0]
                  * fdm->size[1] << 1)) - 1] = r_tmp_data[i0];
    }

    /*  finite differencing at four corners (1,1), (nz,1), (1,nx), (nz,nx) */
    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &ub_emlrtBCI, sp);
    i0 = fdm->size[1];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &vb_emlrtBCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(1, 1, a_size[0], &ib_emlrtBCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(1, 1, a_size[1], &jb_emlrtBCI, sp);
    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &kb_emlrtBCI, sp);
    i0 = fdm->size[1];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &lb_emlrtBCI, sp);
    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &mb_emlrtBCI, sp);
    i0 = fdm->size[1];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &nb_emlrtBCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(1, 1, a_size[0], &ob_emlrtBCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(1, 1, a_size[1], &pb_emlrtBCI, sp);
    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(2, 1, i0, &qb_emlrtBCI, sp);
    i0 = fdm->size[1];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &rb_emlrtBCI, sp);
    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &sb_emlrtBCI, sp);
    i0 = fdm->size[1];
    emlrtDynamicBoundsCheckFastR2012b(2, 1, i0, &tb_emlrtBCI, sp);
    fdm->data[fdm->size[0] * fdm->size[1] << 1] = (SD->f0.b_data[0] * fdm->
      data[fdm->size[0] * fdm->size[1]] - fdm->data[0]) + SD->f0.a_data[0] *
      (fdm->data[1 + fdm->size[0] * fdm->size[1]] + fdm->data[fdm->size[0] +
       fdm->size[0] * fdm->size[1]]);
    i0 = fdm->size[1];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &dc_emlrtBCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(1, 1, a_size[1], &wb_emlrtBCI, sp);
    i0 = fdm->size[1];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &xb_emlrtBCI, sp);
    i0 = fdm->size[1];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &yb_emlrtBCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(1, 1, a_size[1], &ac_emlrtBCI, sp);
    i0 = fdm->size[1];
    emlrtDynamicBoundsCheckFastR2012b(2, 1, i0, &bc_emlrtBCI, sp);
    i0 = fdm->size[1];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &cc_emlrtBCI, sp);
    i0 = fdm->size[0];
    i1 = fdm->size[0];
    i2 = fdm->size[0];
    i3 = fdm->size[0];
    i4 = fdm->size[0];
    i5 = model_size[0] - 1;
    fdm->data[(emlrtDynamicBoundsCheckFastR2012b(model_size[0], 1, i0,
                &cf_emlrtBCI, sp) + (fdm->size[0] * fdm->size[1] << 1)) - 1] =
      (SD->f0.b_data[emlrtDynamicBoundsCheckFastR2012b(model_size[0], 1, a_size
        [0], &df_emlrtBCI, sp) - 1] * fdm->data
       [(emlrtDynamicBoundsCheckFastR2012b(model_size[0], 1, i1, &ef_emlrtBCI,
         sp) + fdm->size[0] * fdm->size[1]) - 1] - fdm->
       data[emlrtDynamicBoundsCheckFastR2012b(model_size[0], 1, i2, &ff_emlrtBCI,
        sp) - 1]) + SD->f0.a_data[emlrtDynamicBoundsCheckFastR2012b(model_size[0],
      1, a_size[0], &gf_emlrtBCI, sp) - 1] * (fdm->data
      [((emlrtDynamicBoundsCheckFastR2012b(model_size[0], 1, i3, &hf_emlrtBCI,
      sp) + fdm->size[0]) + fdm->size[0] * fdm->size[1]) - 1] + fdm->data
      [(emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &if_emlrtBCI, sp) +
        fdm->size[0] * fdm->size[1]) - 1]);
    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &kc_emlrtBCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(1, 1, a_size[0], &ec_emlrtBCI, sp);
    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &fc_emlrtBCI, sp);
    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &gc_emlrtBCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(1, 1, a_size[0], &hc_emlrtBCI, sp);
    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &ic_emlrtBCI, sp);
    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(2, 1, i0, &jc_emlrtBCI, sp);
    i0 = fdm->size[1];
    i1 = fdm->size[1];
    i2 = fdm->size[1];
    i3 = fdm->size[1];
    i4 = model_size[1] - 1;
    i5 = fdm->size[1];
    fdm->data[fdm->size[0] * (emlrtDynamicBoundsCheckFastR2012b(model_size[1], 1,
      i0, &jf_emlrtBCI, sp) - 1) + (fdm->size[0] * fdm->size[1] << 1)] =
      (SD->f0.b_data[a_size[0] * (emlrtDynamicBoundsCheckFastR2012b(model_size[1],
         1, a_size[1], &kf_emlrtBCI, sp) - 1)] * fdm->data[fdm->size[0] *
       (emlrtDynamicBoundsCheckFastR2012b(model_size[1], 1, i1, &lf_emlrtBCI, sp)
        - 1) + fdm->size[0] * fdm->size[1]] - fdm->data[fdm->size[0] *
       (emlrtDynamicBoundsCheckFastR2012b(model_size[1], 1, i2, &mf_emlrtBCI, sp)
        - 1)]) + SD->f0.a_data[a_size[0] * (emlrtDynamicBoundsCheckFastR2012b
      (model_size[1], 1, a_size[1], &nf_emlrtBCI, sp) - 1)] * (fdm->data
      [fdm->size[0] * (emlrtDynamicBoundsCheckFastR2012b(i4, 1, i3, &of_emlrtBCI,
      sp) - 1) + fdm->size[0] * fdm->size[1]] + fdm->data[(fdm->size[0] *
      (emlrtDynamicBoundsCheckFastR2012b(model_size[1], 1, i5, &pf_emlrtBCI, sp)
       - 1) + fdm->size[0] * fdm->size[1]) + 1]);
    i0 = fdm->size[0];
    i1 = fdm->size[1];
    i2 = fdm->size[0];
    i3 = fdm->size[1];
    i4 = fdm->size[0];
    i5 = fdm->size[1];
    ndbl = fdm->size[0];
    cdiff = model_size[0] - 1;
    absb = fdm->size[1];
    apnd = fdm->size[0];
    loop_ub = fdm->size[1];
    i6 = model_size[1] - 1;
    fdm->data[((emlrtDynamicBoundsCheckFastR2012b(model_size[0], 1, i0,
      &qf_emlrtBCI, sp) + fdm->size[0] * (emlrtDynamicBoundsCheckFastR2012b
      (model_size[1], 1, i1, &rf_emlrtBCI, sp) - 1)) + (fdm->size[0] * fdm->
                size[1] << 1)) - 1] = (SD->f0.b_data
      [(emlrtDynamicBoundsCheckFastR2012b(model_size[0], 1, a_size[0],
      &sf_emlrtBCI, sp) + a_size[0] * (emlrtDynamicBoundsCheckFastR2012b
      (model_size[1], 1, a_size[1], &tf_emlrtBCI, sp) - 1)) - 1] * fdm->data
      [((emlrtDynamicBoundsCheckFastR2012b(model_size[0], 1, i2, &uf_emlrtBCI,
      sp) + fdm->size[0] * (emlrtDynamicBoundsCheckFastR2012b(model_size[1], 1,
      i3, &vf_emlrtBCI, sp) - 1)) + fdm->size[0] * fdm->size[1]) - 1] -
      fdm->data[(emlrtDynamicBoundsCheckFastR2012b(model_size[0], 1, i4,
      &wf_emlrtBCI, sp) + fdm->size[0] * (emlrtDynamicBoundsCheckFastR2012b
      (model_size[1], 1, i5, &xf_emlrtBCI, sp) - 1)) - 1]) + SD->f0.a_data
      [(emlrtDynamicBoundsCheckFastR2012b(model_size[0], 1, a_size[0],
         &yf_emlrtBCI, sp) + a_size[0] * (emlrtDynamicBoundsCheckFastR2012b
         (model_size[1], 1, a_size[1], &ag_emlrtBCI, sp) - 1)) - 1] * (fdm->
      data[((emlrtDynamicBoundsCheckFastR2012b(cdiff, 1, ndbl, &bg_emlrtBCI, sp)
             + fdm->size[0] * (emlrtDynamicBoundsCheckFastR2012b(model_size[1],
      1, absb, &cg_emlrtBCI, sp) - 1)) + fdm->size[0] * fdm->size[1]) - 1] +
      fdm->data[((emlrtDynamicBoundsCheckFastR2012b(model_size[0], 1, apnd,
      &dg_emlrtBCI, sp) + fdm->size[0] * (emlrtDynamicBoundsCheckFastR2012b(i6,
      1, loop_ub, &eg_emlrtBCI, sp) - 1)) + fdm->size[0] * fdm->size[1]) - 1]);

    /*  update fdm for next time iteration */
    loop_ub = fdm->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      tmp_data[i0] = i0;
    }

    absb = fdm->size[1];
    for (i0 = 0; i0 < absb; i0++) {
      b_tmp_data[i0] = i0;
    }

    iv7[0] = loop_ub;
    iv7[1] = absb;
    i0 = fdm->size[0];
    i1 = fdm->size[1];
    x_fdm_size[0] = i0;
    x_fdm_size[1] = i1;
    for (i0 = 0; i0 < 2; i0++) {
      b_model_size[i0] = x_fdm_size[i0];
    }

    emlrtSubAssignSizeCheckR2012b(iv7, 2, b_model_size, 2, &v_emlrtECI, sp);
    ndbl = fdm->size[0];
    cdiff = fdm->size[1];
    for (i0 = 0; i0 < cdiff; i0++) {
      for (i1 = 0; i1 < ndbl; i1++) {
        SD->f0.v_data[i1 + ndbl * i0] = fdm->data[(i1 + fdm->size[0] * i0) +
          fdm->size[0] * fdm->size[1]];
      }
    }

    for (i0 = 0; i0 < cdiff; i0++) {
      for (i1 = 0; i1 < ndbl; i1++) {
        fdm->data[tmp_data[i1] + fdm->size[0] * b_tmp_data[i0]] = SD->
          f0.v_data[i1 + ndbl * i0];
      }
    }

    loop_ub = fdm->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      tmp_data[i0] = i0;
    }

    absb = fdm->size[1];
    for (i0 = 0; i0 < absb; i0++) {
      b_tmp_data[i0] = i0;
    }

    iv8[0] = loop_ub;
    iv8[1] = absb;
    i0 = fdm->size[0];
    i1 = fdm->size[1];
    y_fdm_size[0] = i0;
    y_fdm_size[1] = i1;
    for (i0 = 0; i0 < 2; i0++) {
      b_model_size[i0] = y_fdm_size[i0];
    }

    emlrtSubAssignSizeCheckR2012b(iv8, 2, b_model_size, 2, &w_emlrtECI, sp);
    ndbl = fdm->size[0];
    cdiff = fdm->size[1];
    for (i0 = 0; i0 < cdiff; i0++) {
      for (i1 = 0; i1 < ndbl; i1++) {
        SD->f0.v_data[i1 + ndbl * i0] = fdm->data[(i1 + fdm->size[0] * i0) +
          (fdm->size[0] * fdm->size[1] << 1)];
      }
    }

    for (i0 = 0; i0 < cdiff; i0++) {
      for (i1 = 0; i1 < ndbl; i1++) {
        fdm->data[(tmp_data[i1] + fdm->size[0] * b_tmp_data[i0]) + fdm->size[0] *
          fdm->size[1]] = SD->f0.v_data[i1 + ndbl * i0];
      }
    }

    /*  apply absorbing boundary conditions to 3 sides (not surface) */
    for (apnd = 0; apnd < 20; apnd++) {
      loop_ub = c_n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        i1 = fdm->size[0];
        d0 = izb_data[i0];
        i2 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &e_emlrtDCI, sp);
        s_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
          &fg_emlrtBCI, sp) - 1;
      }

      i0 = fdm->size[1];
      i1 = 1 + apnd;
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &mc_emlrtBCI, sp);
      i0 = fdm->size[1];
      i1 = 1 + apnd;
      i0 = emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &lc_emlrtBCI, sp);
      f_tmp_size[0] = c_n + 1;
      loop_ub = c_n + 1;
      for (i1 = 0; i1 < loop_ub; i1++) {
        i2 = fdm->size[0];
        i3 = (int32_T)izb_data[i1];
        t_tmp_data[i1] = boundary[apnd] * fdm->data
          [(emlrtDynamicBoundsCheckFastR2012b(i3, 1, i2, &gg_emlrtBCI, sp) +
            fdm->size[0] * (i0 - 1)) - 1];
      }

      iv9[0] = c_n + 1;
      emlrtSubAssignSizeCheckR2012b(iv9, 1, f_tmp_size, 1, &x_emlrtECI, sp);
      loop_ub = c_n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        fdm->data[s_tmp_data[i0] + fdm->size[0] * apnd] = t_tmp_data[i0];
      }

      loop_ub = c_n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        i1 = fdm->size[0];
        i2 = (int32_T)izb_data[i0];
        s_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
          &hg_emlrtBCI, sp) - 1;
      }

      i0 = fdm->size[1];
      i1 = 1 + apnd;
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &oc_emlrtBCI, sp);
      i0 = fdm->size[1];
      i1 = 1 + apnd;
      i0 = emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &nc_emlrtBCI, sp);
      f_tmp_size[0] = c_n + 1;
      loop_ub = c_n + 1;
      for (i1 = 0; i1 < loop_ub; i1++) {
        i2 = fdm->size[0];
        i3 = (int32_T)izb_data[i1];
        t_tmp_data[i1] = boundary[apnd] * fdm->data
          [((emlrtDynamicBoundsCheckFastR2012b(i3, 1, i2, &ig_emlrtBCI, sp) +
             fdm->size[0] * (i0 - 1)) + fdm->size[0] * fdm->size[1]) - 1];
      }

      iv10[0] = c_n + 1;
      emlrtSubAssignSizeCheckR2012b(iv10, 1, f_tmp_size, 1, &y_emlrtECI, sp);
      loop_ub = c_n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        fdm->data[(s_tmp_data[i0] + fdm->size[0] * apnd) + fdm->size[0] *
          fdm->size[1]] = t_tmp_data[i0];
      }

      ndbl = (model_size[1] + apnd) - 19;
      loop_ub = c_n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        i1 = fdm->size[0];
        i2 = (int32_T)izb_data[i0];
        s_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
          &jg_emlrtBCI, sp) - 1;
      }

      i0 = fdm->size[1];
      emlrtDynamicBoundsCheckFastR2012b(ndbl, 1, i0, &qc_emlrtBCI, sp);
      i0 = (model_size[1] - ndbl) + 1;
      emlrtDynamicBoundsCheckFastR2012b(i0, 1, 20, &kg_emlrtBCI, sp);
      i0 = fdm->size[1];
      cdiff = emlrtDynamicBoundsCheckFastR2012b(ndbl, 1, i0, &pc_emlrtBCI, sp);
      f_tmp_size[0] = c_n + 1;
      loop_ub = c_n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        i1 = fdm->size[0];
        i2 = (int32_T)izb_data[i0];
        t_tmp_data[i0] = boundary[model_size[1] - ndbl] * fdm->data
          [(emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &lg_emlrtBCI, sp) +
            fdm->size[0] * (cdiff - 1)) - 1];
      }

      iv11[0] = c_n + 1;
      emlrtSubAssignSizeCheckR2012b(iv11, 1, f_tmp_size, 1, &ab_emlrtECI, sp);
      loop_ub = c_n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        fdm->data[s_tmp_data[i0] + fdm->size[0] * (ndbl - 1)] = t_tmp_data[i0];
      }

      loop_ub = c_n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        i1 = fdm->size[0];
        i2 = (int32_T)izb_data[i0];
        s_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
          &mg_emlrtBCI, sp) - 1;
      }

      i0 = fdm->size[1];
      emlrtDynamicBoundsCheckFastR2012b(ndbl, 1, i0, &sc_emlrtBCI, sp);
      i0 = (model_size[1] - ndbl) + 1;
      emlrtDynamicBoundsCheckFastR2012b(i0, 1, 20, &ng_emlrtBCI, sp);
      i0 = fdm->size[1];
      cdiff = emlrtDynamicBoundsCheckFastR2012b(ndbl, 1, i0, &rc_emlrtBCI, sp);
      f_tmp_size[0] = c_n + 1;
      loop_ub = c_n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        i1 = fdm->size[0];
        i2 = (int32_T)izb_data[i0];
        t_tmp_data[i0] = boundary[model_size[1] - ndbl] * fdm->data
          [((emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &og_emlrtBCI, sp) +
             fdm->size[0] * (cdiff - 1)) + fdm->size[0] * fdm->size[1]) - 1];
      }

      iv12[0] = c_n + 1;
      emlrtSubAssignSizeCheckR2012b(iv12, 1, f_tmp_size, 1, &bb_emlrtECI, sp);
      loop_ub = c_n + 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        fdm->data[(s_tmp_data[i0] + fdm->size[0] * (ndbl - 1)) + fdm->size[0] *
          fdm->size[1]] = t_tmp_data[i0];
      }

      ndbl = (model_size[0] + apnd) - 19;
      i0 = fdm->size[0];
      emlrtDynamicBoundsCheckFastR2012b(ndbl, 1, i0, &uc_emlrtBCI, sp);
      loop_ub = fdm->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        b_tmp_data[i0] = i0;
      }

      i0 = (model_size[0] - ndbl) + 1;
      emlrtDynamicBoundsCheckFastR2012b(i0, 1, 20, &pg_emlrtBCI, sp);
      absb = fdm->size[1];
      i0 = fdm->size[0];
      cdiff = emlrtDynamicBoundsCheckFastR2012b(ndbl, 1, i0, &tc_emlrtBCI, sp);
      g_tmp_size[0] = 1;
      g_tmp_size[1] = absb;
      for (i0 = 0; i0 < absb; i0++) {
        b_model_data[i0] = boundary[model_size[0] - ndbl] * fdm->data[(cdiff +
          fdm->size[0] * i0) - 1];
      }

      iv13[0] = 1;
      iv13[1] = loop_ub;
      emlrtSubAssignSizeCheckR2012b(iv13, 2, g_tmp_size, 2, &cb_emlrtECI, sp);
      for (i0 = 0; i0 < absb; i0++) {
        fdm->data[(ndbl + fdm->size[0] * b_tmp_data[i0]) - 1] = b_model_data[i0];
      }

      i0 = fdm->size[0];
      emlrtDynamicBoundsCheckFastR2012b(ndbl, 1, i0, &wc_emlrtBCI, sp);
      loop_ub = fdm->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        b_tmp_data[i0] = i0;
      }

      i0 = (model_size[0] - ndbl) + 1;
      emlrtDynamicBoundsCheckFastR2012b(i0, 1, 20, &qg_emlrtBCI, sp);
      absb = fdm->size[1];
      i0 = fdm->size[0];
      cdiff = emlrtDynamicBoundsCheckFastR2012b(ndbl, 1, i0, &vc_emlrtBCI, sp);
      g_tmp_size[0] = 1;
      g_tmp_size[1] = absb;
      for (i0 = 0; i0 < absb; i0++) {
        b_model_data[i0] = boundary[model_size[0] - ndbl] * fdm->data[((cdiff +
          fdm->size[0] * i0) + fdm->size[0] * fdm->size[1]) - 1];
      }

      iv14[0] = 1;
      iv14[1] = loop_ub;
      emlrtSubAssignSizeCheckR2012b(iv14, 2, g_tmp_size, 2, &db_emlrtECI, sp);
      for (i0 = 0; i0 < absb; i0++) {
        fdm->data[((ndbl + fdm->size[0] * b_tmp_data[i0]) + fdm->size[0] *
                   fdm->size[1]) - 1] = b_model_data[i0];
      }

      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
    }

    /*  update data */
    loop_ub = data->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_tmp_data[i0] = i0;
    }

    i0 = data->size[1];
    i1 = (int32_T)(2.0 + (real_T)it);
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &ad_emlrtBCI, sp);
    i0 = fdm->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &xc_emlrtBCI, sp);
    iv15[0] = loop_ub;
    i0 = fdm->size[1];
    ab_fdm_size[0] = 1;
    ab_fdm_size[1] = i0;
    for (i0 = 0; i0 < 2; i0++) {
      b_model_size[i0] = ab_fdm_size[i0];
    }

    emlrtSubAssignSizeCheckR2012b(iv15, 1, b_model_size, 2, &fb_emlrtECI, sp);
    absb = fdm->size[1];
    for (i0 = 0; i0 < absb; i0++) {
      b_model_data[i0] = fdm->data[fdm->size[0] * i0 + fdm->size[0] * fdm->size
        [1]];
    }

    for (i0 = 0; i0 < loop_ub; i0++) {
      data->data[b_tmp_data[i0] + data->size[0] * (it + 1)] = b_model_data[i0];
    }

    /*     %{ */
    /*     figure(3),imagesc(data'); */
    /*     title(['Time index: ',num2str(it)]) */
    /*     colormap seismic */
    /*     drawnow */
    /*     %} */
    loop_ub = snapshot->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      tmp_data[i0] = i0;
    }

    absb = snapshot->size[1];
    for (i0 = 0; i0 < absb; i0++) {
      b_tmp_data[i0] = i0;
    }

    i0 = snapshot->size[2];
    i1 = (int32_T)(2.0 + (real_T)it);
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &bd_emlrtBCI, sp);
    iv16[0] = loop_ub;
    iv16[1] = absb;
    i0 = fdm->size[0];
    i1 = fdm->size[1];
    bb_fdm_size[0] = i0;
    bb_fdm_size[1] = i1;
    for (i0 = 0; i0 < 2; i0++) {
      b_model_size[i0] = bb_fdm_size[i0];
    }

    emlrtSubAssignSizeCheckR2012b(iv16, 2, b_model_size, 2, &gb_emlrtECI, sp);
    loop_ub = fdm->size[0] - 1;
    absb = fdm->size[1] - 1;
    for (i0 = 0; i0 <= absb; i0++) {
      for (i1 = 0; i1 <= loop_ub; i1++) {
        snapshot->data[(tmp_data[i1] + snapshot->size[0] * b_tmp_data[i0]) +
          snapshot->size[0] * snapshot->size[1] * (it + 1)] = fdm->data[i1 +
          fdm->size[0] * i0];
      }
    }

    it++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
  }

  emxFree_real_T(&fdm);

  /*  time loop */
  /* data = data(21:nx-20,:); */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (fm2d.c) */
