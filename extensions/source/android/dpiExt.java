/*
java implementation of the dpiExt extension.

Add android-specific functionality here.

These functions are called via JNI from native code.
*/
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
import com.ideaworks3d.marmalade.LoaderAPI;
import android.util.DisplayMetrics;
import com.ideaworks3d.marmalade.LoaderActivity;


class dpiExt
{
    public int dpiExtGetDeviceDPI()
    {
	DisplayMetrics metrics = new DisplayMetrics();
	LoaderActivity.m_Activity.getWindowManager().getDefaultDisplay().getMetrics(metrics);
	return (int)(metrics.density*160.0f);
    }
}
