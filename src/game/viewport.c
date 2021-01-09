#include <gbi.h>

int z_buffer_width, z_buffer_height;
int z_buffer = 0;

void zbufDeallocate(void) { z_buffer = 0; }

int getPlayerCount(void);

void zbufAllocate(void) {
  unsigned int mempAllocBytesInBank(unsigned int bytes, unsigned char bank);

  extern int resolution;
  if (resolution != 0) {
    z_buffer_width = 440;
    z_buffer_height = 330;
  } else {
    z_buffer_width = 320;
    if (getPlayerCount() == 1) {
      z_buffer_height = 240;
    } else {
      z_buffer_height = 120;
    }
  }
  z_buffer =
      mempAllocBytesInBank((z_buffer_width * z_buffer_height * 2) + 64, 4);
#define ALIGN64(val) (((val) + 0x3F) & ~0x3F)
  z_buffer = ALIGN64(z_buffer);
}

void zbufSetBuffer(int vp_image, int vp_width, int vp_height) {
  z_buffer = vp_image;
  z_buffer_width = vp_width;
  z_buffer_height = vp_height;
}

Gfx *zbufInit(Gfx *gdl) {
  int phi_a3;
  int test;
  if (z_buffer == 0) {
    zbufAllocate();
  }
  if (!(get_cur_playernum() < 2) ||
      ((getPlayerCount() == 2) && (get_cur_playernum() == 1))) {
    phi_a3 = 320 * 240;
  } else {
    phi_a3 = 0;
  }
  test = (z_buffer - phi_a3);
  test = test & ~0x3F;
  gDPPipeSync(gdl++);
  gDPSetDepthImage(gdl++, test);
  return gdl;
}

Gfx *zbufClearCurrentPlayer(Gfx *gdl) {
  short get_video2_settings_txtClipW(void);
  short get_video2_settings_txtClipH(void);

  int start_x;
  int end_x;
  gDPPipeSync(gdl++);
  gDPSetRenderMode(gdl++, G_RM_NOOP, G_RM_NOOP2);
  gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, z_buffer_width,
                   (z_buffer + 0x80000000));
  gDPSetCycleType(gdl++, G_CYC_FILL);
  gDPSetFillColor(gdl++,
                  (GPACK_ZDZ(G_MAXFBZ, 0) << 16 | GPACK_ZDZ(G_MAXFBZ, 0)));
  gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, get_video2_settings_txtClipW(),
                get_video2_settings_txtClipH());
  if (getPlayerCount() < 3) {
    start_x = 0;
    end_x = get_video2_settings_txtClipW() - 1;
  } else if ((get_cur_playernum() == 0) || (get_cur_playernum() == 2)) {
    start_x = 0;
    end_x = (get_video2_settings_txtClipW() / 2) - 1;
  } else {
    start_x = get_video2_settings_txtClipW() / 2;
    end_x = get_video2_settings_txtClipW() - 1;
  }
  gDPFillRectangle(gdl++, start_x, 0, end_x, (z_buffer_height - 1));
  gDPPipeSync(gdl++);
  return gdl;
}