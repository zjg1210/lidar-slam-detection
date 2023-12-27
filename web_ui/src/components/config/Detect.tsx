import { Box, Chip, Grid, InputAdornment, TextField, Typography } from "@mui/material";
import { Autocomplete } from "@mui/material";
import yup from "@plugins/yup-extended";
import { useFormik } from "formik";
import produce from "immer";
import * as React from "react";
import { useEffect, useImperativeHandle } from "react";

const validationSchema = yup.object({
  freespace: yup.object({
    min_height: yup.number().typeError("invalidNumber").required("invalidNumber"),
    max_height: yup.number().typeError("invalidNumber").required("invalidNumber"),
    resolution: yup
      .number()
      .typeError("invalidNumber")
      .required("invalidNumber")
      .min(0.1, "invalidFreespaceResolution")
      .max(1, "invalidFreespaceResolution"),
  }),
});

type Value = LSD.Config["output"];
type ObjectKey = keyof Value["object"];
export interface Props {
  initialValues: Value;
  t?: (x: string | undefined) => string;
}

export interface Ref {
  values: Value;
  isValid: boolean;
  validationSchema: typeof validationSchema;
}

function Detect({ initialValues, t = (x) => x || "" }: Props, ref: React.Ref<Ref>) {
  const formik = useFormik({
    initialValues,
    validationSchema,
    onSubmit: (values) => {},
  });

  useImperativeHandle(ref, () => ({
    ...formik,
    validationSchema,
  }));

  useEffect(() => {
    formik.setValues(initialValues);
  }, [initialValues]);

  const { values, setValues, handleChange, touched, errors } = formik;

  const classCandidateArray = [];
  const classActiveArray = [];
  for (let key of [...Object.keys(values.object), "freespace"]) {
    if (key === "use") continue;
    classCandidateArray.push(key);
    if (key === "freespace") {
      if (values.freespace.use) classActiveArray.push(key);
    } else if (values.object[key as ObjectKey]) {
      classActiveArray.push(key);
    }
  }

  return (
    <Box flexGrow={1}>
      <Typography variant="subtitle2" className="subtitle-no-mt">
        {t("objects")}
      </Typography>
      <Box mb="1rem">
        <Autocomplete
          options={classCandidateArray}
          value={classActiveArray}
          onChange={(e, items) => {
            console.log(e, items);
            setValues(
              produce((output) => {
                for (let key in values.object) {
                  if (key !== "use") output.object[key as ObjectKey] = items.includes(key);
                }
                output.freespace.use = items.includes("freespace");
              })
            );
          }}
          multiple
          filterSelectedOptions
          renderTags={(value, getTagProps) =>
            value.map((optionValue, index) => (
              <Chip variant="outlined" label={t(optionValue)} {...getTagProps({ index })} />
            ))
          }
          renderInput={(params) => <TextField {...params} placeholder="" />}
          renderOption={(props, option) => (
            <Box component="li" {...props}>
              {t(option)}
            </Box>
          )}
        />
      </Box>

      {values.freespace.use && (
        <>
          <Typography variant="subtitle2" className="subtitle">
            {t("freespace")}
          </Typography>
          <Grid container>
            <Grid item md>
              <TextField
                label={t("minHeight")}
                value={values.freespace.min_height}
                InputProps={{
                  endAdornment: <InputAdornment position="end">m</InputAdornment>,
                }}
                onChange={handleChange}
                name="freespace.min_height"
                error={Boolean(errors?.freespace?.min_height)}
                helperText={t(errors?.freespace?.min_height)}
              />
            </Grid>
            <Grid item md>
              <TextField
                label={t("maxHeight")}
                value={values.freespace.max_height}
                InputProps={{
                  endAdornment: <InputAdornment position="end">m</InputAdornment>,
                }}
                onChange={handleChange}
                name="freespace.max_height"
                error={Boolean(errors?.freespace?.max_height)}
                helperText={t(errors?.freespace?.max_height)}
              />
            </Grid>
            <Grid item md>
              <TextField
                label={t("resolution")}
                value={values.freespace.resolution}
                InputProps={{
                  endAdornment: <InputAdornment position="end">m</InputAdornment>,
                }}
                onChange={handleChange}
                name="freespace.resolution"
                error={Boolean(errors?.freespace?.resolution)}
                helperText={t(errors?.freespace?.resolution)}
              />
            </Grid>
          </Grid>
        </>
      )}
    </Box>
  );
}

export default React.memo(React.forwardRef(Detect));
