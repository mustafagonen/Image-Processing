M_hsvtorgb function in C

gbFColor* color = NULL;
    double c = 0.0, m = 0.0, x = 0.0;
    if (Hsl_IsValid(h, s, l) == true)
    {
        c = (1.0 - fabs(2 * l - 1.0)) * s;
        m = 1.0 * (l - 0.5 * c);
        x = c * (1.0 - fabs(fmod(h / 60.0, 2) - 1.0));
        if (h >= 0.0 && h < (HUE_UPPER_LIMIT / 6.0))
        {
            color = RgbF_Create(c + m, x + m, m);
        }
        else if (h >= (HUE_UPPER_LIMIT / 6.0) && h < (HUE_UPPER_LIMIT / 3.0))
        {
            color = RgbF_Create(x + m, c + m, m);
        }
        else if (h < (HUE_UPPER_LIMIT / 3.0) && h < (HUE_UPPER_LIMIT / 2.0))
        {
            color = RgbF_Create(m, c + m, x + m);
        }
        else if (h >= (HUE_UPPER_LIMIT / 2.0)
                && h < (2.0f * HUE_UPPER_LIMIT / 3.0))
        {
            color = RgbF_Create(m, x + m, c + m);
        }
        else if (h >= (2.0 * HUE_UPPER_LIMIT / 3.0)
                && h < (5.0 * HUE_UPPER_LIMIT / 6.0))
        {
            color = RgbF_Create(x + m, m, c + m);
        }
        else if (h >= (5.0 * HUE_UPPER_LIMIT / 6.0) && h < HUE_UPPER_LIMIT)
        {
            color = RgbF_Create(c + m, m, x + m);
        }
        else
        {
            color = RgbF_Create(m, m, m);
        }
    }
    return color;
}

