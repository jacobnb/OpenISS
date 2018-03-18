package openiss.ws.rest;

import openiss.Kinect;
import openiss.utils.PATCH;

import javax.activation.MimetypesFileTypeMap;
import javax.ws.rs.*;
import javax.ws.rs.core.Response;
import javax.ws.rs.core.Response.ResponseBuilder;
import javax.ws.rs.core.MediaType;
import java.awt.datatransfer.MimeTypeParseException;
import java.io.File;

@Path("/openiss")
public class OpenISSRestService {


    static boolean mixFlag = false;
    static boolean cannyFlag = false;
    static boolean contourFlag = false;

    /**
     * Method handling HTTP GET requests. The returned object will be sent
     * to the client as "text/plain" media type.
     *
     * @return String that will be returned as a text/plain response.
     */
    @GET
    @Path("hello")
    @Produces(MediaType.TEXT_PLAIN)
    public String getIt() {
//        Kinect kinect = new Kinect();
//        kinect.initVideo();
//        BufferedImage someimage = kinect.getVideoImage();
        return "Hello World from Jersey API!";
    }

    private static String colorFileName = "src/api/java/openiss/ws/soap/service/color_example.jpg";
    private static String depthFileName = "src/api/java/openiss/ws/soap/service/depth_example.jpg";

    @GET
    @Path("/{type}")
    @Produces("image/*")
    public Response getImage(@PathParam(value = "type") String type) {

        File src;

        // validity checks
        if (!type.equals("rgb") && !type.equals("depth")) {
            return Response.noContent().build();
        }

        if(type.equals("rgb")) {
            src = new File(colorFileName);
        } else {
            src = new File(depthFileName);
        }

        String mt = new MimetypesFileTypeMap().getContentType(src);
        ResponseBuilder response = Response.ok(src, mt);
        return response.build();
    }

    @PATCH
    @Path("/mix")
    @Produces("text/plain")
    public String enableMix() {
        mixFlag = true;
        System.out.println("Mix enabled");
        return getFlags();
    }


    @DELETE
    @Path("/mix")
    @Produces("text/plain")
    public String disableMix() {
        mixFlag = false;
        return getFlags();
    }

    @PATCH
    @Path("/opencv/{type}")
    @Produces("text/plain")
    public String enableOpenCV(@PathParam(value = "type") String type) {

        // validity checks
        if (!type.equals("canny") && !type.equals("contour")) {
            return "Service not supported";
        }

        if (type.equals("canny")) {
            cannyFlag = true;
        } else if(type.equals("contour")) {
            contourFlag = true;
        }
        return getFlags();
    }


    @DELETE
    @Path("/opencv/{type}")
    @Produces("text/plain")
    public String disableOpenCV(@PathParam(value = "type") String type) {

        // validity checksX
        if (!type.equals("canny") && !type.equals("contour")) {
            return "Service not supported.";
        }
        if (type.equals("canny")) {
            cannyFlag = false;
        } else if(type.equals("contour")) {
            contourFlag = false;
        }
        return getFlags();
    }

    private String getFlags() {
        String flags = "Mix: " + String.valueOf(mixFlag) +
                "\nCanny: " + String.valueOf(cannyFlag) +
                "\nContour: " + String.valueOf(contourFlag);
        return flags;
    }



}
